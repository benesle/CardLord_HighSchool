// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CardLord_HighSchoolGameModeBase.h"
#include "CardLord_HighSchool.h"

void ACardLord_HighSchoolGameModeBase::StartPlay()
{
	Super::StartPlay();

	if(GEngine)
	{
		// Display a debug message for five seconds. 
		// The -1 "Key" value (first argument) indicates that we will never need to update or refresh this message.
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPSGameMode!"));
	}
}
