// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCombatAction.h"
#include "CardLord_HighSchool.h"
#include "GameCharacter.h"


	void TestCombatAction::BeginAction(UGameCharacter* character)
	{
		UE_LOG(LogTemp, Log, TEXT("%s this does nothing"), *character->CharacterName);
		//this->delayTimer = 1.0f;

		this->character = character;

		//If the target is dead, select another target
		//Check if HP is more then 0
		if (this->target->HP <= 0)
		{
			this->target = this->character->SelectTarget();
		}

		//If there is no target that is available
		if (this->target == nullptr)
		{
			return;
		}

		if (character->isPlayer)
		{
			if (target->HP > 0 && character->MP > 10)
			{
				AttackDone(character);
				character->MP -= 10;
				UE_LOG(LogTemp, Log, TEXT("%s did the thing"), *character->CharacterName);
			}
			else if (character->MP <= 10)
			{
				AttackDone(character);
				character->isPlayer = false;
			}
		}
		else if (target->HP > 0)
		{
			AttackDone(character);
			character->MP -=10;

		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("%s No more energy"), *character->CharacterName);
		}
		/*	if (target->HP > 0)*/

			//	UE_LOG(LogTemp, Log, TEXT("%s attacks %s"), *character->CharacterName, *target->CharacterName);
			////target->HP -= 10 * (character->ATK / 5) - (target->DEF / 5) >= 0 ? (character->ATK - target->DEF): 0;
			////This will take the targets ATK - targets DEF, but only if the result are greater or equal to 0
			//target->HP -= (character->ATK - target->DEF) >= 0 ? (character->ATK - target->DEF) : 0;


			//this->delayTimer = 1.0f;
		/*}*/

		//If the targets HP is less then 50,  the attack will become stronger
		//else
		//{
			//UE_LOG(LogTemp, Log, TEXT("%s attacks %s"), *character->CharacterName, *target->CharacterName);
			//target->HP -= 10 * (character->ATK / 5) - (target->DEF / 10) >= 0 ? (character->ATK - target->DEF) : 0;
			//target->HP -= (character->ATK - target->DEF) >= 0 ? (character->ATK - target->DEF) : 0;


			//Check of strong the attack is 
			/*target->ATK;
			int32 TotalDamage = 10 * (character->ATK / 5) - (target->DEF / 10);
			target->HP -= TotalDamage;
			FString AttackLog = FString::Printf(TEXT("%02d"), TotalDamage);
			UE_LOG(LogTemp, Error, TEXT("%s atk %s"), *character->CharacterName, *AttackLog);*/
		/*}*/
			//this->delayTimer = 1.0f;
	}

	void TestCombatAction::AttackDone(UGameCharacter* character)
	{

		//if (target->HP > 0)

		UE_LOG(LogTemp, Log, TEXT("%s attacks %s"), *character->CharacterName, *target->CharacterName);
		target->HP -= (character->ATK - target->DEF) >= 0 ? (character->ATK - target->DEF) : 0;

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


