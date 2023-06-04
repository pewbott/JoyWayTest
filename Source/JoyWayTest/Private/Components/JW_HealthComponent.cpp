// JoyWay Test Work // Isunts D.D.

#include "JW_HealthComponent.h"

UJW_HealthComponent::UJW_HealthComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UJW_HealthComponent::BeginPlay()
{
    Super::BeginPlay();

    SetHealth(MaxHealth);

    AActor* Owner = GetOwner();
    if (Owner)
    {
        Owner->OnTakeAnyDamage.AddDynamic(this, &UJW_HealthComponent::OnTakeAnyDamageHandle);
    }
}

void UJW_HealthComponent::SetHealth(const float InHealth)
{
    Health = FMath::Clamp(InHealth, 0.0f, MaxHealth);
    OnHealthChanged.ExecuteIfBound(Health);
    if (IsDead()) OnDeath.ExecuteIfBound();
}

void UJW_HealthComponent::OnTakeAnyDamageHandle(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
    if (Damage <= 0.0f || IsDead()) return;
    SetHealth(Health - Damage);
}
