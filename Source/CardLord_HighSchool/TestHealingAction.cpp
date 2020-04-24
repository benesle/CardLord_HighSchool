// Fill out your copyright notice in the Description page of Project Settings.


#include "TestHealingAction.h"
#include "CardLord_HighSchool.h"


void TestHealingAction::BeginAction(UGameCharacter* character)
{
	UE_LOG(LogTemp, Log, TEXT("%s this does nothing"), *character->CharacterName);
	//this->delayTimer = 1.0f;

	this->character = character;

	//If target is dead, select another target
	if (this->character->HP <= 0)
	{
		this->character = this->character->SelectTarget();
	}

	//No target available
	if (this->character == nullptr)
	{
		return;
	}
	//Healing
	if (character->HP > 0)
	{
		UE_LOG(LogTemp, Log, TEXT("%s Heals"), *character->CharacterName);
		character->HP += 50;
		this->delayTimer = 1.0f;
	}
	else
		UE_LOG(LogTemp, Log, TEXT("%s No more potions"), *character->CharacterName);
		character->HP = character->HP;

	/*target->ATK;
	int32 TotalDamage = 10 * (character->ATK / 5) - (target->DEF / 10);
	target->HP -= TotalDamage;
	FString AttackLog = FString::Printf(TEXT("%02d"), TotalDamage);
	UE_LOG(LogTemp, Error, TEXT("%s atk %s"), *character->CharacterName, *AttackLog);*/
	this->delayTimer = 1.0f;
}

bool TestHealingAction::DoAction(float DeltaSeconds)
{
	this->delayTimer -= DeltaSeconds;
	return this->delayTimer <= 0.0f;
}

TestHealingAction::TestHealingAction(UGameCharacter* character)
{
	this->character = character;
}

