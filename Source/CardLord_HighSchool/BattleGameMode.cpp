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

	if (enemyTable == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Enemies data table not found!"));
		return;
	}

	//Find enemis
	FEnemyData* row = enemyTable->FindRow<FEnemyData>(TEXT("P1"), TEXT("LookupEnemyData"));
	enemyTable->FindRow<FEnemyData>(TEXT("P1"), TEXT("LookupEnemyData"));

	if (row == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Enemy ID 'P1' not found!"));
		return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy Found"));
	}

	// add character to enemy party
	UGameCharacter* enemy = UGameCharacter::CreateGameCharacter(row, this);
	if (enemy)
	{
		this->enemyGroup.Add(enemy);
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("NO enemy"));

	///////////////////////////////////////////////////

	//Find enemyData
	/*UDataTable* enemyTable =*/ //Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("DataTable'/Game/DataTable/Enemy.Enemy'")));
	//Find enemis
	FEnemyData* row1 = enemyTable->FindRow<FEnemyData>(TEXT("P2"), TEXT("LookupEnemyData"));

	if (row1 == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Enemy ID 'P2' not found!"));
		return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy Found"));
	}
	///////////////////////////////////////////////////////////////

		// add character to enemy party
UGameCharacter* enemy1 = UGameCharacter::CreateGameCharacter(row1, this);
	if (enemy1)
	{
		this->enemyGroup.Add(enemy1);
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("NO enemy"));


	

	// disable player actor
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetActorTickEnabled(false);

	// add character to enemy party
	///*UGameCharacter* */enemy = UGameCharacter::CreateGameCharacter(row, this);
	//if (enemy)
	//{
	//	this->enemyGroup.Add(enemy);
	//}
	//else
	//	UE_LOG(LogTemp, Warning, TEXT("NO enemy"));



	if (enemyTable == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Enemies data table not found!"));
		return;
	}

	UCardLordGameInstance* gameInstance = Cast<UCardLordGameInstance>(GetGameInstance());

	this->currentCombatInstance = new CombatManager(gameInstance->GroupMembers, this->enemyGroup);

	UE_LOG(LogTemp, Log, TEXT("Combat started"));

	this->CombatUIInstance = CreateWidget<UCombatUI>(GetGameInstance(), this->CombatUIClass);
	this->CombatUIInstance->AddToViewport();

	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;

	//Player
	for (int i = 0; i < gameInstance->GroupMembers.Num(); i++)

	{
		this->CombatUIInstance->AddPlayerCharacterWid(gameInstance->GroupMembers[i]);
		gameInstance->GroupMembers[i]->decisionMaker = this->CombatUIInstance;
	}

	//Enemy
	for (int i = 0; i < this->enemyGroup.Num(); i++)
	{
		this->CombatUIInstance->AddEnemyCharacterWid(this->enemyGroup[i]);
	}


}

ABattleGameMode::ABattleGameMode(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DefaultPawnClass = AMyCharacter::StaticClass();
}

void ABattleGameMode::BeginPlay()
{
	if (Cast<UCardLordGameInstance>(GetGameInstance()))
	{
		Cast<UCardLordGameInstance>(GetGameInstance())->Init();
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;
		TestCombat();
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("No Game Instance in begin play BattleGameMode"));



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
				Cast<UCardLordGameInstance>(GetGameInstance())->PrepareReset();

				UUserWidget* GameOverInstance = CreateWidget<UUserWidget>(GetGameInstance(), this->GameOverClass);
				if(GameOverInstance)
				GameOverInstance->AddToViewport();
			}

			else if (this->currentCombatInstance->gameState == CombatState::CSTATE_Win)
			{
				UE_LOG(LogTemp, Log, TEXT("Player wins combat"));
				GetWorld()->ServerTravel(FString("/Game/Maps/Floor_1"));
			}

			for (int i = 0; i < currentCombatInstance->playerGroup.Num(); i++)
			{
				this->currentCombatInstance->playerGroup[i]->decisionMaker = nullptr;
			}

			UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = false;

			//Player actor enable
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetActorTickEnabled(true);

			if(CombatUIInstance)
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

