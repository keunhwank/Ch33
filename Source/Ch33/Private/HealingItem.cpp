#include "HealingItem.h"

AHealingItem::AHealingItem()
{

  HealAmount = 20;
  ItemType = "Healing";

}

void AHealingItem::ActivateItem(AActor* Activator)
{
  if (Activator && Activator->ActorHasTag("Player"))
  {
    GEngine->AddOnScreenDebugMessage(-1,
      2.0f,
      FColor::Green,
      FString::Printf(TEXT("Player Gained %d HP!!"), HealAmount));
    DestroyItem();
  }
}