// JoyWay Test Work // Isunts D.D.

#include "JW_BaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

AJW_BaseCharacter::AJW_BaseCharacter()
{
    PrimaryActorTick.bCanEverTick = false;

    GetCharacterMovement()->bOrientRotationToMovement = true;

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(GetRootComponent());
    SpringArmComponent->bUsePawnControlRotation = true;

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);
}

void AJW_BaseCharacter::MoveForward(const float InValue)
{
    AddMovementInput(GetActorForwardVector(), InValue);
}

void AJW_BaseCharacter::MoveRight(const float InValue)
{
    AddMovementInput(GetActorRightVector(), InValue);
}
