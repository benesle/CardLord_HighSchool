// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CardLord_HighSchoolGameModeBase.h"
#include "CardLord_HighSchool.h"
#include "UObject/ConstructorHelpers.h"

void ACardLord_HighSchoolGameModeBase::StartPlay()
{
	Super::StartPlay();

	//if(GEngine)
	//{
	//	// Display a debug message for five seconds. 
	//	// The -1 "Key" value (first argument) indicates that we will never need to update or refresh this message.
	//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPSGameMode!"));
	//}
}

ACardLord_HighSchoolGameModeBase::ACardLord_HighSchoolGameModeBase()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Character/Player/Blueprints/BP_SideCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
	DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
