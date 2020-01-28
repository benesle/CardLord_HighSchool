// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleGameModeBase.h"
#include "CardLord_HighSchool.h"
#include "MyCharacterBaseBattle.h"
#include "CombatUserInterface.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
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
Benedicte

	static ConstructorHelpers::FClassFinder<UUserWidget> CombatUserInterface(TEXT("/Game/Character/Player/Blueprints/BP_MyCharacterBaseBattle"));
	HUDWidgetClass = CombatUserInterface.Class;

	// use our custom HUD class
	HUDClass = UCombatUserInterface::StaticClass();

	// add Health Bar UI to viewport
	if (HUDWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);

		if (CurrentWidget)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

void ABattleGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	SetCurrentState(EGamePlayState::EPlaying);

	MyCharacter = Cast<AMyCharacterBaseBattle>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void ABattleGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MyCharacter)
	{
		if (FMath::IsNearlyZero(MyCharacter->GetHealth(), 0.001f))
		{
			SetCurrentState(EGamePlayState::EGameOver);
		}
	}
}

EGamePlayState ABattleGameModeBase::GetCurrentState() const
{
	return CurrentState;
}

void ABattleGameModeBase::SetCurrentState(EGamePlayState NewState)
{
	CurrentState = NewState;
	HandleNewState(CurrentState);
}

void ABattleGameModeBase::HandleNewState(EGamePlayState NewState)
{
	switch (NewState)
	{
	case EGamePlayState::EGameOver:
	{
		// do nothing
	}
	break;
	// Unknown/default state
	case EGamePlayState::EBattle:
	{
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
	}
	break;
	// Unknown/default state
	default:
	case EGamePlayState::EPlaying:
	{
		// do nothing
	}
	break;
=======
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Character/Player/Blueprints/BP_MyCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
 master
	}
}

