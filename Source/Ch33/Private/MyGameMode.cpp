#include "MyGameMode.h"
#include "MyCharacter.h"
#include "MyPlayerController.h"
#include "MyGameStateBase.h"

AMyGameMode::AMyGameMode()
{
  DefaultPawnClass = AMyCharacter::StaticClass();
  PlayerControllerClass = AMyPlayerController::StaticClass();
  GameStateClass = AMyGameStateBase::StaticClass();
}

