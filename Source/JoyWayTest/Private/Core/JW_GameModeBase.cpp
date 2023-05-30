// JoyWay Test Work // Isunts D.D.

#include "JW_GameModeBase.h"
#include "JW_Hud.h"
#include "JW_PlayerController.h"

AJW_GameModeBase::AJW_GameModeBase()
{
    PrimaryActorTick.bCanEverTick = false;

    // setup core classes
    PlayerControllerClass = AJW_PlayerController::StaticClass();
    HUDClass = AJW_Hud::StaticClass();
}
