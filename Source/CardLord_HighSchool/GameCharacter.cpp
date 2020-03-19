// Fill out your copyright notice in the Description page of Project Settings.


#include "GameCharacter.h"
#include "CombatManager.h"


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
	}
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

	return character;
}

void UGameCharacter::BeginDestroy()
{
	Super::BeginDestroy();
}

void UGameCharacter::BeginDecision()
{
	UE_LOG(LogTemp, Log, TEXT("Character %s making decision"), *this->CharacterName);
	this->delayTimerTest = 1;
}

bool UGameCharacter::Makedecision(float DeltaSeconds)
{
	this->delayTimerTest -= DeltaSeconds;
	return this->delayTimerTest <= 0;
}

void UGameCharacter::BeginAction()
{
	UE_LOG(LogTemp, Log, TEXT("Character %s executing action"), *this->CharacterName);
	this->delayTimerTest = 1;
}

bool UGameCharacter::DoAction(float DeltaSeconds)
{
	this->delayTimerTest -= DeltaSeconds;
	return this->delayTimerTest <= 0;
}
