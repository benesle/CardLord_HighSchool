// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameCharacter.h"
#include "CombatManager.h"
#include "CardLord_HighSchoolGameModeBase.generated.h"


UCLASS()
class CARDLORD_HIGHSCHOOL_API ACardLord_HighSchoolGameModeBase : public AGameMode
{
	GENERATED_BODY()

		ACardLord_HighSchoolGameModeBase(const class FObjectInitializer& ObjectInitializer);

		virtual void StartPlay() override;

		//Overrided tick function
		virtual void Tick(float DeltaTime) override;

public: 
	//Combat manager instance
	CombatManager* currentCombatInstance;

	//Keep track of all the enemy characters
	TArray<UGameCharacter*> enemyGroup;

	//To test the combat system
	UFUNCTION(exec)
	void TestCombat();
	
};
