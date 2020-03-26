// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ICombatAction.h"
/**
 * 
 */
class CARDLORD_HIGHSCHOOL_API TestCombatAction : public ICombatAction
{

protected: 
	float delayTimer;
	UGameCharacter* character;
	UGameCharacter* target; 

public:

	virtual void BeginAction(UGameCharacter* character) override;
	virtual bool DoAction(float DeltaSeconds) override;
	TestCombatAction(UGameCharacter* target);
};