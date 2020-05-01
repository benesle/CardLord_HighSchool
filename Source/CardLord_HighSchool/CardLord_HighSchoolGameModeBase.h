// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BattleGameMode.h"
#include "GameCharacter.h"
#include "CombatManager.h"
#include "CombatUI.h"
#include "CardLord_HighSchoolGameModeBase.generated.h"


UCLASS()
class CARDLORD_HIGHSCHOOL_API ACardLord_HighSchoolGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

		ACardLord_HighSchoolGameModeBase(const class FObjectInitializer& ObjectInitializer);

	virtual void StartPlay() override;
	//This because just in case thats why something does not work
	//virtual void BeginPlay() override;
	//virtual void Tick(float DeltaTime) override;

public:

	//Just testing something out 

	//Combat manager instance
	//CombatManager* currentCombatInstance;

	////An array with all the enemy group members 
	//TArray<UGameCharacter*> enemyGroup;


	////UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	////	TSubclassOf<class UUserWidget> GameOverClass;

	////UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	////	TSubclassOf<class UCombatUI> CombatUIClass;

	//UPROPERTY()
	//	UCombatUI* CombatUIInstance;
	
};
