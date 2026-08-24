#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemSpawnRow.generated.h"

USTRUCT(BlueprintType)
struct FItemSpawnRow : public FTableRowBase
{
  GENERATED_BODY()

public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FName ItemaName;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  TSubclassOf<AActor> ItemClass;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float SpwanChance;
};
