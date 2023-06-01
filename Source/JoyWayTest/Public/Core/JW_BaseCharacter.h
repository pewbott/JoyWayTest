// JoyWay Test Work // Isunts D.D.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "JW_BaseCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class JOYWAYTEST_API AJW_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AJW_BaseCharacter();
    void MoveForward(float InValue);
    void MoveRight(float InValue);

protected:
    UPROPERTY(VisibleAnywhere)
    UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere)
    USpringArmComponent* SpringArmComponent;
};
