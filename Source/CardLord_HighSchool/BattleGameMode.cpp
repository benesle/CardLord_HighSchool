// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleGameMode.h"
#include "MyPlayerBattle.h"
#include "CardLordGameInstance.h"
#include "MyPlayerController.h"
#include "CardLord_HighSchool.h"
#include "UObject/ConstructorHelpers.h"



void ABattleGameMode::TestCombat()
{
	//Find enemyData
	UDataTable* enemyTable = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("DataTable'/Game/DataTable/Enemy.Enemy'")));

	if (enemyTable == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Enemies data table not found!"));
		return;
	}

	//Find enemis
	FEnemyData* row = enemyTable->FindRow<FEnemyData>(TEXT("P1"), TEXT("LookupEnemyData"));

	if (row == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Enemy ID 'P1' not found!"));
		return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy Found"));
	}

	// disable player actor
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetActorTickEnabled(false);

	// add character to enemy party
	UGameCharacter* enemy = UGameCharacter::CreateGameCharacter(row, this);
	this->enemyGroup.Add(enemy);

	UCardLordGameInstance* gameInstance = Cast<UCardLordGameInstance>(GetGameInstance());

	this->currentCombatInstance = new CombatManager(gameInstance->GroupMembers, this->enemyGroup);

	UE_LOG(LogTemp, Log, TEXT("Combat started"));

	this->CombatUIInstance = CreateWidget<UCombatUI>(GetGameInstance(), this->CombatUIClass);
	this->CombatUIInstance->AddToViewport();

	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;

	for (int i = 0; i < gameInstance->GroupMembers.Num(); i++)
		this->CombatUIInstance->AddPlayerCharacterWid(gameInstance->GroupMembers[i]);

	for (int i = 0; i <this->enemyGroup.Num(); i++)
		this->CombatUIInstance->AddEnemyCharacterWid(this->enemyGroup[i]);

}

ABattleGameMode::ABattleGameMode(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DefaultPawnClass = AMyCharacter::StaticClass();
}

void ABattleGameMode::BeginPlay()
{

	Cast<UCardLordGameInstance>(GetGameInstance())->Init();
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;

  //      Super::BeginPlay();
		///*ChangeMenu(StartingMenuClass);*/

  //      DefaultPawnClass = AMyPlayerBattle::StaticClass();
  //      PlayerControllerClass = AMyPlayerController::StaticClass();
}

void ABattleGameMode::Tick(float DeltaTime)
{
	if (this->currentCombatInstance != nullptr)
	{
		bool combatOver = this->currentCombatInstance->Tick(DeltaTime);
		if (combatOver)
		{
			if (this->currentCombatInstance->gameState == CombatState::CSTATE_GameOver)
			{
				UE_LOG(LogTemp, Log, TEXT("Player loses combat, game over"));
			}
			else if (this->currentCombatInstance->gameState == CombatState::CSTATE_Win)
			{
				UE_LOG(LogTemp, Log, TEXT("Player wins combat"));
			}
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = false;
			//Player actor enable
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetActorTickEnabled(true);

			this->CombatUIInstance->RemoveFromViewport();
			this->CombatUIInstance = nullptr;

			delete(this->currentCombatInstance);
			this->currentCombatInstance = nullptr;
			this->enemyGroup.Empty();
		}
	}
}

//void ABattleGameMode::ChangeMenu(TSubclassOf<UUserWidget> NewMenuClass)
//{
//    if (CurrentMenu != nullptr)
//    {
//        CurrentMenu->RemoveFromViewport();
//        CurrentMenu = nullptr;
//    }
//    if (NewMenuClass != nullptr)
//    {
//        CurrentMenu = CreateWidget<UUserWidget>(GetWorld(), NewMenuClass);
//        if (CurrentMenu != nullptr)
//        {
//            CurrentMenu->AddToViewport();
//        }
//    }
//}

