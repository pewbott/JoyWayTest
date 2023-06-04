// JoyWay Test Work // Isunts D.D.

#include "JW_BaseCharacter.h"

#include "JW_HealthComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

AJW_BaseCharacter::AJW_BaseCharacter()
{
    PrimaryActorTick.bCanEverTick = true; // del

    GetCharacterMovement()->bOrientRotationToMovement = true;

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(GetRootComponent());
    SpringArmComponent->bUsePawnControlRotation = true;

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);

    HealthTextComponent = CreateDefaultSubobject<UTextRenderComponent>("HealthTextComponent");
    HealthTextComponent->SetupAttachment(GetRootComponent());

    HealthComponent = CreateDefaultSubobject<UJW_HealthComponent>("HealthComponent");
}

void AJW_BaseCharacter::BeginPlay()
{
    Super::BeginPlay();

    check(HealthComponent);
    check(HealthTextComponent);

    HealthComponent->OnHealthChanged.BindUObject(this, &AJW_BaseCharacter::OnHealthChangedHandle);
    HealthComponent->OnDeath.BindUObject(this, &AJW_BaseCharacter::OnDeathHandle);

    OnHealthChangedHandle(HealthComponent->GetHealth());
}

void AJW_BaseCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    TakeDamage(0.1f, FDamageEvent(), Controller, this);
}

void AJW_BaseCharacter::OnHealthChangedHandle(const float InHealth)
{
    // todo call delegate to update HP in HUD from controoler, which subscribe to this delegate
    UpdateHealthBar(InHealth);
}

void AJW_BaseCharacter::MoveForward(const float InValue)
{
    AddMovementInput(GetActorForwardVector(), InValue);
}

void AJW_BaseCharacter::MoveRight(const float InValue)
{
    AddMovementInput(GetActorRightVector(), InValue);
}

void AJW_BaseCharacter::UpdateHealthBar(const float InValue) const
{
    HealthTextComponent->SetText(FText::FromString(FString::Printf(TEXT("%.0f"), InValue)));
}

void AJW_BaseCharacter::OnDeathHandle()
{
    GetCharacterMovement()->DisableMovement();
    SetLifeSpan(LifeSpanTime);
    OnDeath.ExecuteIfBound();
}
