// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "TransferStats.generated.h"

/**
 * 
 */
UCLASS()
class CARDLORD_HIGHSCHOOL_API UTransferStats : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = Basic)
		FString PlayerName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	uint32 userIndex;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	uint32 TransferHealth;

	UPROPERTY(VisibleAnywhere, Category = Basic)
		uint32 TransferMana;

	UTransferStats();


};
