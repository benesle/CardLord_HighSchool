// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameCharacter.h"

class UGameCharacter;

class CARDLORD_HIGHSCHOOL_API ICombatAction
{

protected:
	float delayTimer;

public:
	virtual void BeginAction(UGameCharacter* character) = 0;
	virtual bool DoAction(float DeltaSeconds) = 0;

};
