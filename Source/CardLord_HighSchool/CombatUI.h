// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameCharacter.h"
#include "Blueprint/UserWidget.h"
#include "CombatUI.generated.h"

/**
 * 
 */
UCLASS()
class CARDLORD_HIGHSCHOOL_API UCombatUI : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent, Category = "Combat UI")
		void AddPlayerCharacterWid(UGameCharacter* target);

	UFUNCTION(BlueprintImplementableEvent, Category = "Combat UI")
		void AddEnemyCharacterWid(UGameCharacter* target);
	
};
