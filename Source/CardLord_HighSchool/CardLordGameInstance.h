// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameCharacter.h"
#include "CardLordGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CARDLORD_HIGHSCHOOL_API UCardLordGameInstance : public UGameInstance
{
	GENERATED_BODY()

		UCardLordGameInstance(const class FObjectInitializer& ObjectInitializer);

public:
	TArray<UGameCharacter*> GroupMembers;
	void Init();

protected: 
	bool isInit;

	
};
