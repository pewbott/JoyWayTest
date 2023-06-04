// JoyWay Test Work // Isunts D.D.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "JW_HealthComponent.generated.h"

DECLARE_DELEGATE_OneParam(FFloatDelegate, const float);
DECLARE_DELEGATE(FSignalDelegate);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class JOYWAYTEST_API UJW_HealthComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UJW_HealthComponent();
    FORCEINLINE float GetHealth() const {return Health;}

private:
    virtual void BeginPlay() override;
    bool IsDead() const {return Health <= 0.0f;}
    void SetHealth(const float InHealth);

    UFUNCTION()
    void OnTakeAnyDamageHandle(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

public:
    FFloatDelegate OnHealthChanged;
    FSignalDelegate OnDeath;
    
private:
    float MaxHealth = 100.0f;
    float Health = 0.0f;
};
