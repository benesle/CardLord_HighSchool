// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "FCharacterClassData.generated.h"

USTRUCT(BlueprintType)
struct FCharacterClassData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()


		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassData")
			FString Class_Name;

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassData")
			int32 MinHealth;

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassData")
			int32 MinStamina;

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassData")
			int32 MinATK;

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassData")
			int32 MinDEF;

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassData")
			int32 MinCrit;

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassData")
			int32 MaxHealth;

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassData")
			int32 MaxStamina;

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassData")
			int32 MaxATK;

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassData")
			int32 MaxDEF;

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassData")
			int32 MaxCrit;

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassData")
			TArray<FString> StartingAbilities;

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassData")
			TArray<FString> LearnedAbilities;

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClassData")
			TArray<int32> LearnedAbilityLevels;
	};
