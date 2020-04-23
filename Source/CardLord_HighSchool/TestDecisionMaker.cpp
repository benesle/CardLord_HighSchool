// Fill out your copyright notice in the Description page of Project Settings.


#include "TestDecisionMaker.h"
#include "CardLord_HighSchool.h"
#include "TestCombatAction.h"
#include "TestHealingAction.h"


void TestDecisionMaker::BeginDecision(UGameCharacter * character)
{
	AttackChoice(character);
	
	/*if (character)
	{

		UGameCharacter* target = character->SelectTarget();
		character->combatAction = new TestCombatAction(target);


	}
	else
		UE_LOG(LogTemp, Warning, TEXT("No character in TestDecitionMaker.cpp"));*/

}

bool TestDecisionMaker::Makedecision(float DeltaSeconds)
{
	return true;
}

void TestDecisionMaker::AttackChoice(UGameCharacter* character)
{
	if (character)
	{

		UGameCharacter* target = character->SelectTarget();
		character->combatAction = new TestCombatAction(target);


	}
	else
		UE_LOG(LogTemp, Warning, TEXT("No character in TestDecitionMaker.cpp"));
}

void TestDecisionMaker::HealingChoice(UGameCharacter* character)
{
	if (character)
{

		UGameCharacter* target = character->SelectTarget();
		character->combatAction = new TestHealingAction(character);

	}
	else
		UE_LOG(LogTemp, Warning, TEXT("No Healing"));
}

//	void TestDecisionMaker::Heal(UGameCharacter* character)
//{
//	if (HealingChoice)
//	{
//		HealingChoice;
//	}
//}
