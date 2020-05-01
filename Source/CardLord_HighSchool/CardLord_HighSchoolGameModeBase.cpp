// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CardLord_HighSchoolGameModeBase.h"
#include "CardLord_HighSchool.h"
#include "MyCharacter.h"
#include "CardLordGameInstance.h"
#include "UObject/ConstructorHelpers.h"

void ACardLord_HighSchoolGameModeBase::StartPlay()
{
	Super::StartPlay();

	//Cast<UCardLordGameInstance>(GetGameInstance())->Init();

}

//void ACardLord_HighSchoolGameModeBase::Tick(float DeltaTime)
//{
//
//}


//void ACardLord_HighSchoolGameModeBase::TestCombat()
//{
//	
//	
//}

ACardLord_HighSchoolGameModeBase::ACardLord_HighSchoolGameModeBase(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//DefaultPawnClass = AMyCharacter::StaticClass();
	//// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Character/Player/Blueprints/BP_SideCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}



