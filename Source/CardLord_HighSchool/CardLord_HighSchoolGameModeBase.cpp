// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CardLord_HighSchoolGameModeBase.h"
#include "CardLord_HighSchool.h"
#include "MyCharacter.h"
#include "CardLordGameInstance.h"
#include "UObject/ConstructorHelpers.h"

void ACardLord_HighSchoolGameModeBase::StartPlay()
{
	//Super::StartPlay();
	Cast<UCardLordGameInstance>(GetGameInstance())->Init();

}

void ACardLord_HighSchoolGameModeBase::Tick(float DeltaTime)
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
			//Player actor enable
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetActorTickEnabled(true);

			delete(this->currentCombatInstance);
			this->currentCombatInstance = nullptr;
			this->enemyGroup.Empty();
		}
	}
}

void ACardLord_HighSchoolGameModeBase::TestCombat()
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
	
	if( row == nullptr)
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
	
}

ACardLord_HighSchoolGameModeBase::ACardLord_HighSchoolGameModeBase(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//DefaultPawnClass = AMyCharacter::StaticClass();
	//// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Character/Player/Blueprints/BP_SideCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}



