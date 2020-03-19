// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatUI.h"
#include "CardLord_HighSchool.h"
#include "CombatManager.h"
#include "TestCombatAction.h"



//void UCombatUI::AddEnemyCharacterWid(UGameCharacter* target)
//{
//}

TArray<UGameCharacter*> UCombatUI::GetCharacterTarget()
{
	if (this->currentTarget->isPlayer)
	{
		return this->currentTarget->combatInstance->enemyGroup;
	}
	else

	{
		return this->currentTarget->combatInstance->playerGroup;
		//return TArray<UGameCharacter*>();
	}
}

void UCombatUI::AttackTarget(UGameCharacter* target)
{
	TestCombatAction* action = new TestCombatAction(target);
	this->currentTarget->combatAction = action;

	this->madeDecision = true;
}

//void UCombatUI::ShowActionPanel(UGameCharacter* target)
//{
//}

void UCombatUI::BeginDecision(UGameCharacter* target)
{
	this->currentTarget = target;
	this->madeDecision = false;

	ShowActionPanel(target);
}

bool UCombatUI::Makedecision(float DeltaSeconds)
{
	return this->madeDecision;
}
