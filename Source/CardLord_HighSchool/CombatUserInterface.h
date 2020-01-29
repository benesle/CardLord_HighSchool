// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CombatUserInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCombatUserInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CARDLORD_HIGHSCHOOL_API ICombatUserInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//Set up Interface functionality
	virtual FString GetTestName();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category= Interfaces)
	bool ReactToPlayerExited();

	//Declares a function that has to be implemented in C++
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category= Interfaces)
		bool ReactToPlayerEntered();
};
