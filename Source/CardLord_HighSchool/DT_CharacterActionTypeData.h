// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MyCharacter.h"
#include "Engine/DataTable.h"
#include "DT_CharacterActionTypeData.generated.h"

USTRUCT(BlueprintType)
struct FCharacterActionTypeData : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "FCharacterActionTypeData")
        FString ActionType;

    UPROPERTY(BlueprintReadOnly, Category = "FCharacterActionTypeData")
        FString AttackName;

    UPROPERTY(BlueprintReadOnly, Category = "FCharacterActionTypeData")
        FString AttackDisplayName;

    UPROPERTY(BlueprintReadOnly, Category = "FCharacterActionTypeData")
        FString Description;

    UPROPERTY(BlueprintReadOnly, Category = "FCharacterActionTypeData")
        int32 CostStamina;

    UPROPERTY(BlueprintReadOnly, Category = "FCharacterActionTypeData")
        int32 Damage;
};

