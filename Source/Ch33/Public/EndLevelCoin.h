#pragma once

#include "CoreMinimal.h"
#include "CoinItem.h"
#include "EndLevelCoin.generated.h"


UCLASS()
class CH33_API AEndLevelCoin : public ACoinItem
{
	GENERATED_BODY()
	
public:
	virtual void ActivateItem(AActor* Activator) override;
};
