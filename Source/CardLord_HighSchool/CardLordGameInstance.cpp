// Fill out your copyright notice in the Description page of Project Settings.

#include "CardLord_HighSchool.h"
#include "CardLordGameInstance.h"



UCardLordGameInstance::UCardLordGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	isInit = false;
}

void UCardLordGameInstance::Init()
{
	if (this->isInit)
		return;
	this->isInit = true;

	//Find the characters Data

	UDataTable* characters = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("DataTable'/Game/DataTable/Character.Character'")));
	
	if (characters == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Characters data table not found!:("));
		//return;
	}

	//Find characters
	FCharacterData* row = characters->FindRow<FCharacterData>(TEXT("P1"), TEXT("LookupCharcterClass"));

	if (row == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Character ID 'P1' not found!!!"));
		//return;
	}

	//Add Character to the group
	this->GroupMembers.Add(UGameCharacter::CreateGameCharacter(row, this));
}
