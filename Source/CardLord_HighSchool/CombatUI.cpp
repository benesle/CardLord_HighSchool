// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatUI.h"
#include "CardLord_HighSchool.h"
#include "CombatManager.h"
#include "TestCombatAction.h"

//Begin the decision making prosess
void UCombatUI::BeginDecision(UGameCharacter* target)
{
	if (target)
	{
		this->currentTarget = target;
		this->madeDecision = false;
		ShowActionPanel(target);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("There is no Target in BeginDecision"));
	}
}

//To check if decission is made and then return the decision
bool UCombatUI::Makedecision(float DeltaSeconds)
{
	return this->madeDecision;
}

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

//To execute the decision to execute the AttackTarget action 
void UCombatUI::AttackTarget(UGameCharacter* target)
{
	TestCombatAction* action = new TestCombatAction(target);
	this->currentTarget->combatAction = action;

	this->madeDecision = true;
}

void UCombatUI::HealTarget(UGameCharacter * target)
{
	TestCombatAction* heal = new TestCombatAction(target);
	this->currentTarget->combatAction = heal;

	this->madeDecision = true;
}

void UCombatUI::FleeTarget(UGameCharacter * target)
{
	TestCombatAction* flee = new TestCombatAction(target);
	this->currentTarget->combatAction = flee;

	this->madeDecision = true;
}

