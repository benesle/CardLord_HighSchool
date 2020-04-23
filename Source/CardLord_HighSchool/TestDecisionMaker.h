// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "IDecisionMaker.h"

class CARDLORD_HIGHSCHOOL_API TestDecisionMaker : public IDecisionMaker
{
public:

	virtual void BeginDecision(UGameCharacter* character) override;
	virtual bool Makedecision(float DeltaSeconds) override;
	void AttackChoice(UGameCharacter* character);
	void HealingChoice(UGameCharacter* character);
	void Heal(UGameCharacter* character);
};
