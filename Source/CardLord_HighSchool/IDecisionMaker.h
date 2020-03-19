// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameCharacter.h"

class UGameCharacter;

class IDecisionMaker
{
public:
	virtual void BeginDecision(UGameCharacter* character) = 0;
	virtual bool Makedecision(float DeltaSeconds) = 0;
};
