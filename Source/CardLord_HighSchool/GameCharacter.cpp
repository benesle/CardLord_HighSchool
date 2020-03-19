// Fill out your copyright notice in the Description page of Project Settings.


#include "GameCharacter.h"
#include "CombatManager.h"
#include "TestCombatAction.h"
#include "TestDecisionMaker.h"


UGameCharacter* UGameCharacter::CreateGameCharacter(FCharacterData* characterData, UObject* outer)
{
	UGameCharacter* character = NewObject<UGameCharacter>(outer);

	// locate character classes asset
	UDataTable* characterClass = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("DataTable'/Game/DataTable/CharacterClass.CharacterClass'")));
	
	if (characterClass == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Character classes datatable not found!"));
	}
	else
	{
		character->CharacterName = characterData->Character_Name;
		FCharacterClassData* row = characterClass->FindRow<FCharacterClassData>(*(characterData->Class_ID), TEXT("LookupCharacterClass"));
		character->ClassData = row;

		character->Health = character->ClassData->MinHealth;
		character->Stamina = character->ClassData->MinStamina;
		character->HP = character->Health;
		character->MP = character->Stamina;

		character->ATK = character->ClassData->MinATK;
		character->DEF = character->ClassData->MinDEF;
		character->Crit = character->ClassData->MinCrit;

		character->decisionMaker = new TestDecisionMaker();
	}
	
	character->isPlayer = true;
	return character;
}

UGameCharacter* UGameCharacter::CreateGameCharacter(FEnemyData* enemyData, UObject* outer)
{
	UGameCharacter* character = NewObject<UGameCharacter>(outer);

	character->CharacterName = enemyData->EnemyName;
	character->ClassData = nullptr;

	character->Health = enemyData->Health;
	character->Stamina = 0;
	character->HP = enemyData->Health;
	character->MP = 0;

	character->ATK = enemyData->ATK;
	character->DEF = enemyData->DEF;
	character->Crit = enemyData->Crit;

	character->decisionMaker = new TestDecisionMaker();
	character->isPlayer = false;
	return character;
}

UGameCharacter * UGameCharacter::SelectTarget()
{
	UGameCharacter* target = nullptr;

	TArray<UGameCharacter*> targetList = this->combatInstance->enemyGroup;

	if (!this->isPlayer)
	{
		targetList = this->combatInstance->playerGroup;
	}

	for (int i = 0; i < targetList.Num(); i++)
	{
		if (targetList[i]->HP > 0)
		{
			target = targetList[i];
			break;
		}
	}

	if (target->HP <= 0)
	{
		return nullptr;
	}

	return target;
}

void UGameCharacter::BeginDestroy()
{
	Super::BeginDestroy();
	delete(this->decisionMaker);

}

void UGameCharacter::BeginDecision()
{
	UE_LOG(LogTemp, Log, TEXT("Character %s making decision"), *this->CharacterName);
	this->decisionMaker->BeginDecision(this);
	//this->combatAction = new TestCombatAction();
}

bool UGameCharacter::Makedecision(float DeltaSeconds)
{
	//return true;
	return this->decisionMaker->Makedecision(DeltaSeconds);
}

void UGameCharacter::BeginAction()
{
	UE_LOG(LogTemp, Log, TEXT("Character %s executing action"), *this->CharacterName);
	this->combatAction->BeginAction(this);
}

bool UGameCharacter::DoAction(float DeltaSeconds)
{
	bool actionDone = this->combatAction->DoAction(DeltaSeconds);
	
	//Checks if action is done
	if (actionDone)
	{
		delete(this->combatAction);
		return true;
	}

	return false;
}
