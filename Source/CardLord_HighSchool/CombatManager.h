// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardLord_HighSchool.h"
#include "GameCharacter.h"

enum class CombatState : uint8
{
	CSTATE_Decision,
	CSTATE_Action,
	CSTATE_Win,
	CSTATE_GameOver,
};
class CARDLORD_HIGHSCHOOL_API CombatManager
{
public:

	CombatManager(TArray<UGameCharacter*> playerGroup, TArray<UGameCharacter*> enemyGroup);
	~CombatManager();

	TArray<UGameCharacter*> combatTurn;
	TArray<UGameCharacter*> playerGroup;
	TArray<UGameCharacter*> enemyGroup;
	TArray<UGameCharacter*> inventory;

	CombatState gameState;

	bool Tick(float DeltaSeconds);
	int32 TotalGold;
	int32 XPTotal;
	int32 ItemIndex;

protected:

	UGameCharacter* currentTickTarget;
	bool waintingForCharacter;
	int tickTargetIndex;
	int tickItemIndex;


	void SetState(CombatState gameState);
	void SelectNextCharacter();
	bool UpdateState(float DeltaSeconds);

};
