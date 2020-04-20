// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCombatAction.h"
#include "CardLord_HighSchool.h"


	void TestCombatAction::BeginAction(UGameCharacter* character)
	{
		UE_LOG(LogTemp, Log, TEXT("%s this does nothing"), *character->CharacterName);
		//this->delayTimer = 1.0f;

		this->character = character;

		//If target is dead, select another target
		if (this->target->HP <= 0)
		{
			this->target = this->character->SelectTarget();

		}

		//No target available
		if (this->target == nullptr)
		{
			return;
		}

			//Attack option
			UE_LOG(LogTemp, Log, TEXT("%s attacks %s"), *character->CharacterName, *target->CharacterName);
			target->HP -= 10 * (character->ATK / 5) - (target->DEF / 10);
			this->delayTimer = 1.0f;
	}

	bool TestCombatAction::DoAction(float DeltaSeconds)
	{
		this->delayTimer -= DeltaSeconds;
		return this->delayTimer <= 0.0f;
	}

	TestCombatAction::TestCombatAction(UGameCharacter* target)
	{
		this->target = target;
	}

