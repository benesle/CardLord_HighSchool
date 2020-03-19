// Fill out your copyright notice in the Description page of Project Settings.


#include "TestDecisionMaker.h"
#include "CardLord_HighSchool.h"
#include "TestCombatAction.h"


void TestDecisionMaker::BeginDecision(UGameCharacter * character)
{
	//character->combatAction = new TestCombatAction();
	//Choose Target
	UGameCharacter* target = character->SelectTarget();
	character->combatAction = new TestCombatAction(target);

}

bool TestDecisionMaker::Makedecision(float DeltaSeconds)
{
	return true;
}
