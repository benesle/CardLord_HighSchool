// Fill out your copyright notice in the Description page of Project Settings.

#include "CardLordGameInstance.h"
#include "CardLord_HighSchool.h"




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

	/////////////////////////PLAYER1//////////////////////////////////
	if (characters == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Characters 'P1' data table not found!:("));
		//return;
	}

	//Find characters
	FCharacterData* row = characters->FindRow<FCharacterData>(TEXT("P1"), TEXT("LookupCharcterClass"));
	//FCharacterData* row1 = characters->FindRow<FCharacterData>(TEXT("P2"), TEXT("LookupCharcterClass"));

	if (row == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Character ID not found!!!"));
		//return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Found"));
	}

	this->GroupMembers.Add(UGameCharacter::CreateGameCharacter(row, this));
	

	//Add Character to the group
	//FCharacterData* row1 = characters->FindRow<FCharacterData>(TEXT("P2"), TEXT("LookupCharcterClass"));

	//if (row1 == NULL)
	//{
	//	UE_LOG(LogTemp, Error, TEXT("Character ID 'P2' not found!!!"));
	//	return;
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Player Found"));
	//}
	

	//row = characters->FindRow<FCharacterData>(TEXT("P2"), TEXT("LookupCharcterClass"));
	///////Player2
	//UGameCharacter* characters1 = UGameCharacter::CreateGameCharacter(row, this);
	//if (characters1)
	//{
	//	this->GroupMembers.Add(characters1);

	//}
	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("NO player"));
	//}

	/////////////////PLAYER2///////////////////////////////////////
	/*FCharacterData* row1 = characters->FindRow<FCharacterData>(TEXT("P2"), TEXT("LookupCharcterClass"));

	if (row1 == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Character ID 'P2' not found!!!"));
		return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Found"));
	}

	//Add character to the group
	UGameCharacter* characters2 = UGameCharacter::CreateGameCharacter(row1, this);
	this->GroupMembers.Add(UGameCharacter::CreateGameCharacter(row1, this));


	if (characters == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Characters 'P2' data table not found!:("));
		//return;
	}*/


	///////////////////////////////////////////////
		//Find the characters Data
	//
	//UDataTable* characters1 = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("DataTable'/Game/DataTable/Character.Character'")));

	////Find characters


	
	////////////////////////////////////////////

	////Add Character to the group

}


void UCardLordGameInstance::PrepareReset()
{
	this->isInit = false;
	this->GroupMembers.Empty();
}