// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Blueprint/UserWidget.h"
#include "CombatUserInterface.generated.h"

// This class does not need to be modified.
//UINTERFACE(MinimalAPI)
//class UCombatUserInterface : public UInterface
//{
//	GENERATED_BODY()
//};

/**
 * 
 */
UCLASS()
class CARDLORD_HIGHSCHOOL_API UCombatUserInterface: public UUserWidget
{
	GENERATED_BODY()


	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
protected:

	//Set up Interface functionality
	virtual FString GetTestName();

	//Players Health
	UFUNCTION(BlueprintPure, Category = "Widget|Gameplay")
		float GetCurrentHealth();

	//Players Stamina/Motivation
	UFUNCTION(BlueprintPure, Category = "Widget|Gameplay")
		float GetCurrentStamina();

	//Players Money balance
	UFUNCTION(BlueprintPure, Category = "Widget|Gameplay")
		int GetCurrentMoney();
};
