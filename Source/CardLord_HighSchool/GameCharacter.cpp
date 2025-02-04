// Fill out your copyright notice in the Description page of Project Settings.


#include "GameCharacter.h"
#include "CombatManager.h"
#include "TestCombatAction.h"
#include "TestDecisionMaker.h"
#include "DT_CharacterActionTypeData.h"

//Creates the player character and gives it stats based on FCharacterData
UGameCharacter* UGameCharacter::CreateGameCharacter(FCharacterData* characterData, UObject* outer)
{
	UGameCharacter* character = NewObject<UGameCharacter>(outer);

	// locate the character class data
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
		character->XP = character->ClassData->XP;
		character->MaxXP = character->ClassData->MaxXP;
		character->Lvl = character->ClassData->Lvl;
		character->LearnedAbilities = character->ClassData->LearnedAbilities;
		character->StartingAbillities = character->ClassData->StartingAbilities;

		character->isPlayer = true;
	}
	return character;

}

//Creates the enemy and gets data from FEnemyData(DataTable)
UGameCharacter* UGameCharacter::CreateGameCharacter(FEnemyData* enemyData, UObject* outer)
{
	UGameCharacter* character = NewObject<UGameCharacter>(outer);
	
	if (enemyData)
	{
		character->CharacterName = enemyData->EnemyName;
		character->ClassData = nullptr;

		character->Health = enemyData->Health;
		character->Stamina = 0;
		character->HP = enemyData->Health;
		character->MP = 0;

		character->ATK = enemyData->ATK;
		character->DEF = enemyData->DEF;
		character->Crit = enemyData->Crit;
		character->XP = enemyData->XP;
		character->Gold = enemyData->Gold;

		//Dont Remove this
		character->decisionMaker = new TestDecisionMaker();
		character->isPlayer = false;
		return character;
	}
	else

	UE_LOG(LogTemp, Log, TEXT("No enemyData"));


	//Dont Remove this
	character->decisionMaker = new TestDecisionMaker();

	character->isPlayer = false;
	return character;
}

//Tried to Create an Inventory
//UGameCharacter* UGameCharacter::CreateInventory(FItemData* itemData, UObject* outer)
//{
//	UGameCharacter* item = NewObject<UGameCharacter>(outer);
//
//	if (itemData)
//	{
//		item->HP;
//		item->MP;
//
//		item->decisionMaker = new TestDecisionMaker();
//		item->isPlayer = true;
//		return item;
//	}
//	else
//		UE_LOG(LogTemp, Log, TEXT("No ItemData"));
//
//	item->decisionMaker = new TestDecisionMaker();
//	item->isPlayer = true;
//	return item;

//}

//Selecter Target from enemyGroup if HP is above 0
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

	//if(target)
	if (target->HP <= 0)
	{
		return nullptr;
	}

	return target;
}

////Tried to add the functionallity to make the player choose between actions 
//UGameCharacter* UGameCharacter::SelectAction()
//{
//	UGameCharacter* actions = nullptr;
//
//	TArray<UGameCharacter*> actionList = this->combatInstance->inventory;
//
//	if (this->isPlayer)
//	{
//		actionList = this->combatInstance->inventory;
//	}
//
//	for (int i = 0; i < actionList.Num(); i++)
//	{
//		if (actionList[i]->HP > 0)
//		{
//			actions = actionList[i];
//			break;
//		}
//	}
//
//	if(actions)
//		if (actions->HP <= 0)
//		{
//			return nullptr;
//		}
//
//	return actions;
//}


void UGameCharacter::BeginDestroy()
{
	//The decision maker will be the UI for the player 
	Super::BeginDestroy();

	if (!this->isPlayer)
	{
		delete(this->decisionMaker);
	}
}

//Begin the decisionMaking
void UGameCharacter::BeginDecision()
{
	UE_LOG(LogTemp, Log, TEXT("Character %s making decision"), *this->CharacterName);

	if (decisionMaker)
	{
		this->decisionMaker->BeginDecision(this);
		//this->combatAction = new TestCombatAction();
	}
	else
		UE_LOG(LogTemp, Log, TEXT("stuck on begin decision"), *this->CharacterName)
}

//Check decision is available 
bool UGameCharacter::Makedecision(float DeltaSeconds)
{
	//return true;
	if (decisionMaker)
	{
		return this->decisionMaker->Makedecision(DeltaSeconds);
	}
	else
		UE_LOG(LogTemp, Log, TEXT("DecisionMaker is nullptr"), *this->CharacterName)
		return false;
}

//Begin doing the action
void UGameCharacter::BeginAction()
{
	if (combatAction)
	{
		UE_LOG(LogTemp, Log, TEXT("Character %s executing action"), *this->CharacterName);
		this->combatAction->BeginAction(this);
	}
	else
		UE_LOG(LogTemp, Log, TEXT("stuck on begin action"), *this->CharacterName);
}

//Check if action is available 
bool UGameCharacter::DoAction(float DeltaSeconds)
{
	bool actionDone = this->combatAction->DoAction(DeltaSeconds);
	
	//Checks if action is done
	if (actionDone)
	{
		delete(this->combatAction);
		return true;
	}
	else
	UE_LOG(LogTemp, Log, TEXT("Wainting"), *this->CharacterName);

	return false;
}
