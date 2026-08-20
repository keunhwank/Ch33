#include "HealingItem.h"

AHealingItem::AHealingItem()
{

  HealAmount = 20;
  ItemType = "Healing";

}

void AHealingItem::ActivateItem(AActor* Activator)
{
  DestroyItem();
}