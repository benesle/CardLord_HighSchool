// Fill out your copyright notice in the Description page of Project Settings.

#include "CombatUserInterface.h"
#include "Runtime/Core/Public/Internationalization/Text.h"
#include "MyCharacterBaseBattle.h"

// Add default functionality here for any ICombatUserInterface functions that are not pure virtual.
FString UCombatUserInterface::GetTestName()
{
	unimplemented();
	return FString();
}

float UCombatUserInterface::GetCurrentHealth()
{
	//Getting access to player class that owns this widget and check if player is valid
	if (AMyCharacterBaseBattle* Player = Cast<AMyCharacterBaseBattle>(GetOwningPlayerPawn()))
	{
		//Getting the current and Max health and dividing them for a value between 0 and 1 
		//Then clamping that value so it cant be out of range
		return (FMath::Clamp<float>(Player->GetCurrentHealth() / Player->GetMaxHealth(), 0.0f, 1.0f));
	}
	//return value as a float, if fail 0.5
	return 0.5f;
}

float UCombatUserInterface::GetCurrentStamina()
{
	//Getting access to player class that owns this widget and check if player is valid
	if (AMyCharacterBaseBattle* Player = Cast<AMyCharacterBaseBattle>(GetOwningPlayerPawn()))
	{
		//Getting the current and Max StaMINA and dividing them for a value between 0 and 1 
		//Then clamping that value so it cant be out of range
		return (FMath::Clamp<float>(Player->GetCurrentStamina() / Player->GetMaxStamina(), 0.0f, 1.0f));
	}
	//return value as a float, if fail 0.5
	return 0.5f;
}

int UCombatUserInterface::GetCurrentMoney()
{

	////Getting access to player class that owns this widget and check if player is valid
	//if (AMyCharacterBaseBattle* Player = Cast<AMyCharacterBaseBattle>(GetOwningPlayerPawn()))
	//{
	//	//Getting the current and Max StaMINA and dividing them for a value between 0 and 1 
	//	//Then clamping that value so it cant be out of range
	//	return (FMath::Clamp<float>(Player->GetCurrentMoney () / Player->GetMaxMoney(), 0.0f, 1.0f));
	//}
	////return value as a float, if fail 0.5
	//return 0.5f;
}