// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "FCharacterData.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FCharacterData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterData")
	FString Character_Name;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "CharacterData")
	FString Class_ID;
	
};
