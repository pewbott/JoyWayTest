// JoyWay Test Work // Isunts D.D.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "JW_PlayerController.generated.h"

class AJW_BaseCharacter;

UCLASS()
class JOYWAYTEST_API AJW_PlayerController : public APlayerController
{
    GENERATED_BODY()

private:
    virtual void SetupInputComponent() override;
    virtual void OnPossess(APawn* InPawn) override;
    void MoveForwardAxisHandle(float InValue);
    void MoveRightAxisHandle(float InValue);
    void JumpActionPressedHandle();
    void JumpActionReleasedHandle();

private:
    UPROPERTY()
    AJW_BaseCharacter* CurrentCharacter = nullptr;
};
