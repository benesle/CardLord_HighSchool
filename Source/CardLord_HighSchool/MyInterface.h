// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CARDLORD_HIGHSCHOOL_API IMyInterface
{
	GENERATED_IINTERFACE_BODY()

public:
	//Decleration of a function for reaction to player entered battle, that must be implementated in C++
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Interface)
		bool ReactToBattleEntered();

};
