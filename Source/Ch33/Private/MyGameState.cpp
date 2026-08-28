#include "MyGameState.h"
#include "MyGameInstance.h"
#include "MyPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "SpawnVolume.h"
#include "CoinItem.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"


AMyGameState::AMyGameState()
{
  Score = 0;
  SpawnedCoinCount = 0;
  CollectedCoinCount = 0;
  LevelDurations = { 30.0f, 30.0f, 30.0f };
  CurrentLevelIndex = 0;
  MaxLevels = 3;
  WaveGoalCoin = { 10, 15, 50 };
  WaveSpawnCount = { 40, 60, 100 };
  WaveDurations = { 10.0f, 15.0f, 20.0f };
}

void AMyGameState::BeginPlay()
{
  Super::BeginPlay();
  
  StartLevel();

  GetWorldTimerManager().SetTimer(
    HUDUpdateTimerHandle,
    this,
    &AMyGameState::UpdateHUD,
    0.1f,
    true
  );
}

int32 AMyGameState::GetScore() const
{
  return Score;
}

void AMyGameState::AddScore(int32 Amount)
{
  if (UGameInstance* GameInstance = GetGameInstance())
  {
    UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GameInstance);
    if (MyGameInstance)
    {
      MyGameInstance->AddToScore(Amount);
    }
  }
}

void AMyGameState::StartLevel()
{
  // HUD 보여주기
  if (APlayerController* PlayerController =
    GetWorld()->GetFirstPlayerController())
  {
    if (AMyPlayerController* MyPlayerController =
      Cast<AMyPlayerController>(PlayerController))
    {
      MyPlayerController->ShowGameHUD();
    }
  }

  // 저장된 Level Index 불러오기
  if (UGameInstance* GameInstance = GetGameInstance())
  {
    UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GameInstance);

    if (MyGameInstance)
    {
      CurrentLevelIndex =
        MyGameInstance->CurrentLevelIndex;
    }
  }

  CurrentWaveIndex = 0;

  StartWave();

  UpdateHUD();
  if (LevelDurations.IsValidIndex(CurrentLevelIndex))
  {
    const float CurrentLevelDurations =
      LevelDurations[CurrentLevelIndex];
    GetWorldTimerManager().SetTimer(
      LevelTimerHandle,
      this,
      &AMyGameState::OnLevelTimeUp,
      CurrentLevelDurations,
      false
    );
  }
  UE_LOG(
    LogTemp,
    Warning,
    TEXT("Level %d Start!"),
    CurrentLevelIndex + 1
  );
}

void AMyGameState::OnLevelTimeUp()
{
  EndLevel();
}

void AMyGameState::OnCoinCollected()
{
  CollectedCoinCount++;
  UE_LOG(LogTemp, Warning, TEXT("Coin Collected: %d / %d"), 
    CollectedCoinCount,
    SpawnedCoinCount)


    if (WaveGoalCoin.IsValidIndex(CurrentWaveIndex) && CollectedCoinCount >= WaveGoalCoin[CurrentWaveIndex])
    {
      EndWave();
    }
}

void AMyGameState::EndLevel()
{
  GetWorldTimerManager().ClearTimer(LevelTimerHandle);
 
  if (UGameInstance* GameInstance = GetGameInstance())
  {
    UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GameInstance);
    if (MyGameInstance)
    {
      AddScore(Score);
      CurrentLevelIndex++;
      MyGameInstance->CurrentLevelIndex = CurrentLevelIndex;
    }
  }

  if (CurrentLevelIndex >= MaxLevels)
  {
    OnGameOver();
    return;
  }

  if (LevelMapNames.IsValidIndex(CurrentLevelIndex))
  {
    UGameplayStatics::OpenLevel(GetWorld(), LevelMapNames[CurrentLevelIndex]);
  }
  else
  {
    OnGameOver();
  }
}

void AMyGameState::OnGameOver()
{
  if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
  {
    if (AMyPlayerController* MyPlayerController = Cast<AMyPlayerController>(PlayerController))
    {
      MyPlayerController->SetPause(true);
      MyPlayerController->ShowMainMenu(true);
    }
  }
}

void AMyGameState::UpdateHUD()
{
  if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
  {
    if (AMyPlayerController* MyPlayerController = Cast<AMyPlayerController>(PlayerController))
    {
      if (UUserWidget* HUDWidget = MyPlayerController->GetHUDWidget())
      {
        if (UTextBlock* TimeText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Time"))))
        {
          float RemainingTime = GetWorldTimerManager().GetTimerRemaining(LevelTimerHandle);
          TimeText->SetText(FText::FromString(FString::Printf(TEXT("Time: % .1f"), RemainingTime)));
        }

        if (UTextBlock* ScoreText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Score"))))
        {
          if (UGameInstance* GameInstance = GetGameInstance())
          {
            UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GameInstance);
            if (MyGameInstance)
            {
              ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score: %d"), MyGameInstance->TotalScore)));
            }
          }
        }

        if (UTextBlock* LevelIndexText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Level"))))
        {
          LevelIndexText->SetText(FText::FromString(FString::Printf(TEXT("Level: %d"), CurrentLevelIndex + 1)));
        }
      }
    }
  }
}

void AMyGameState::StartWave()
{
  UE_LOG(LogTemp, Warning, TEXT("Wave %d Start"), CurrentWaveIndex + 1);

  SpawnedCoinCount = 0;
  CollectedCoinCount = 0;

  TArray<AActor*> FoundVolumes;
  UGameplayStatics::GetAllActorsOfClass(
    GetWorld(),
    ASpawnVolume::StaticClass(),
    FoundVolumes
  );
  if (WaveSpawnCount.IsValidIndex(CurrentWaveIndex))
  {

    const int32 ItemToSpawn = WaveSpawnCount[CurrentWaveIndex];

    for (int32 i = 0; i < ItemToSpawn; i++)
    {
      if (FoundVolumes.Num() > 0)
      {
        ASpawnVolume* SpawnVolume =
          Cast<ASpawnVolume>(FoundVolumes[0]);

        if (SpawnVolume)
        {
          AActor* SpawnedActor =
            SpawnVolume->SpawnRandomItem();

          if (SpawnedActor &&
            SpawnedActor->IsA(ACoinItem::StaticClass()))
          {
            SpawnedCoinCount++;
          }
        }
      }
    }
  }
}

void AMyGameState::EndWave()
{
  if (WaveDurations.IsValidIndex(CurrentWaveIndex))
  {
    float RemainingTime = GetWorldTimerManager().GetTimerRemaining(LevelTimerHandle);

    RemainingTime += WaveDurations[CurrentWaveIndex];
    GetWorldTimerManager().SetTimer(
      LevelTimerHandle,
      this,
      &AMyGameState::OnLevelTimeUp,
      RemainingTime,
      false
    );
  }

  CurrentWaveIndex++;

  if (WaveGoalCoin.IsValidIndex(CurrentWaveIndex))
  {
    StartWave();
  }
  else
  {
    EndLevel();
  }
  
}
