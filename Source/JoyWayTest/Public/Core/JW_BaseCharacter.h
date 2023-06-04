// JoyWay Test Work // Isunts D.D.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "JW_BaseCharacter.generated.h"

class UTextRenderComponent;
class UJW_HealthComponent;
class USpringArmComponent;
class UCameraComponent;

DECLARE_DELEGATE(FSignalDelegate);

UCLASS()
class JOYWAYTEST_API AJW_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AJW_BaseCharacter();
    void MoveForward(float InValue);
    void MoveRight(float InValue);

private:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override; // del
    void OnHealthChangedHandle(const float InHealth);
    void UpdateHealthBar(const float InValue) const;
    void OnDeathHandle();

public:
    FSignalDelegate OnDeath;
    
protected:
    UPROPERTY(VisibleAnywhere)
    UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere)
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(VisibleAnywhere)
    UJW_HealthComponent* HealthComponent;

    UPROPERTY(VisibleAnywhere)
    UTextRenderComponent* HealthTextComponent; // text component to display character health

private:
    const float LifeSpanTime = 5.0f;
};

