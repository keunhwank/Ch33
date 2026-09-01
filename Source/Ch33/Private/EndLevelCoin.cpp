#include "EndLevelCoin.h"
#include "MyGameState.h"
#include "Engine/World.h"


void AEndLevelCoin::ActivateItem(AActor* Activator)
{
  Super::ActivateItem(Activator);

  if (AMyGameState* AGameState = GetWorld()->GetGameState<AMyGameState>())
  {
    AGameState->AddScore(5000);
    AGameState->EndLevel();
    UE_LOG(LogTemp, Warning, TEXT("OK Next Level!!"));
  }
}
