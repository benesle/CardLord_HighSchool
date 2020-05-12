// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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

	CombatState gameState;

	int32 XPTotal;
	int32 TotalGold;

	bool Tick(float DeltaSeconds);

protected:

	UGameCharacter* currentTickTarget;
	bool waintingForCharacter;
	int tickTargetIndex;


	void SetState(CombatState gameState);
	void SelectNextCharacter();
	bool UpdateState(float DeltaSeconds);

};
