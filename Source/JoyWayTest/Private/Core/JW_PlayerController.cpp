// JoyWay Test Work // Isunts D.D.

#include "JW_PlayerController.h"
#include "JW_BaseCharacter.h"

DEFINE_LOG_CATEGORY_STATIC(LogJW_PlayerController, All, All);

void AJW_PlayerController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    CurrentCharacter = Cast<AJW_BaseCharacter>(InPawn);
    if (!CurrentCharacter)
    {
        UE_LOG(LogJW_PlayerController, Error, TEXT("Failed to cast possessed character to base character class"))
    }
}

void AJW_PlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AJW_PlayerController::JumpActionPressedHandle);
    InputComponent->BindAction("Jump", EInputEvent::IE_Released, this, &AJW_PlayerController::JumpActionReleasedHandle);

    InputComponent->BindAxis("MoveForward", this, &AJW_PlayerController::MoveForwardAxisHandle);
    InputComponent->BindAxis("MoveRight", this, &AJW_PlayerController::MoveRightAxisHandle);
    InputComponent->BindAxis("LookUp", this, &AJW_PlayerController::AddPitchInput);
    InputComponent->BindAxis("Turn", this, &AJW_PlayerController::AddYawInput);
}

void AJW_PlayerController::MoveForwardAxisHandle(float InValue)
{
    if (!CurrentCharacter) return;
    CurrentCharacter->MoveForward(InValue);
}

void AJW_PlayerController::MoveRightAxisHandle(float InValue)
{
    if (!CurrentCharacter) return;
    CurrentCharacter->MoveRight(InValue);
}

void AJW_PlayerController::JumpActionPressedHandle()
{
    if (!CurrentCharacter) return;
    CurrentCharacter->Jump();
}

void AJW_PlayerController::JumpActionReleasedHandle()
{
    if (!CurrentCharacter) return;
    CurrentCharacter->StopJumping();
}
