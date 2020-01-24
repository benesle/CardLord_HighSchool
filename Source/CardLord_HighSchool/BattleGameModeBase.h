// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BattleGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CARDLORD_HIGHSCHOOL_API ABattleGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
		virtual void StartPlay() override;

public: ABattleGameModeBase();
};