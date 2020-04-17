// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameCharacter.h"
#include "Blueprint/UserWidget.h"
#include "CombatUI.generated.h"

/**
 * 
 */
UCLASS()
class CARDLORD_HIGHSCHOOL_API UCombatUI : public UUserWidget, public IDecisionMaker
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent, Category = "Combat UI")
		void AddPlayerCharacterWid(UGameCharacter* target);

	UFUNCTION(BlueprintImplementableEvent, Category = "Combat UI")
		void AddEnemyCharacterWid(UGameCharacter* target);

	UFUNCTION(Blueprintcallable, Category = "Combat UI")
		TArray<UGameCharacter*> GetCharacterTarget();

	UFUNCTION(BlueprintCallable, Category = "Combat UI")
		void AttackTarget(UGameCharacter* target);

	UFUNCTION(BlueprintImplementableEvent, Category = "Combat UI")
		void ShowActionPanel(UGameCharacter* target);

	UFUNCTION(BlueprintCallable, Category = "Combat UI")
		void HealTarget(UGameCharacter* target);

	UFUNCTION(BlueprintCallable, Category = "Combat UI")
		void FleeTarget(UGameCharacter* target);

protected:

	UGameCharacter* currentTarget;
	bool madeDecision;

public:
 
	void BeginDecision(UGameCharacter* target);
	bool Makedecision(float DeltaSeconds);

	
	
};
