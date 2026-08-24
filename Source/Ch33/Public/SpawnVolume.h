#pragma once

#include "CoreMinimal.h"
#include "ItemSpawnRow.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

class UBoxComponent;

UCLASS()
class CH33_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawnVolume();
	
	UPROPERTY(VisibleAnywhere, blueprintReadOnly, Category = "Spawning")
	USceneComponent* Scene;
	UPROPERTY(VisibleAnywhere, blueprintReadOnly, Category = "Spawning")
	UBoxComponent* SpawningBox;
	UPROPERTY(EditAnywhere, blueprintReadOnly, Category = "Spawning")
	UDataTable* ItemDataTable;

	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void SpawnRandomItem();

	FItemSpawnRow* GetRandomItem() const;
	void SpawnItem(TSubclassOf<AActor> ItemClass);
	FVector GetRandomPointInVolume() const;
};
