// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleGameModeBase.h"
#include "CardLord_HighSchool.h"
#include "UObject/ConstructorHelpers.h"

void ABattleGameModeBase::StartPlay()
{
	Super::StartPlay();

	//if(GEngine)
	//{
	//	// Display a debug message for five seconds. 
	//	// The -1 "Key" value (first argument) indicates that we will never need to update or refresh this message.
	//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPSGameMode!"));
	//}
}

ABattleGameModeBase::ABattleGameModeBase()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Character/Player/Blueprints/BP_MyCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

