// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "FEnemyData.generated.h"


USTRUCT(BlueprintType)
struct FEnemyData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EnemyData")
		FString EnemyName;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "EnemyData")
		int32 Health;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "EnemyData")
		int32 ATK;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "EnemyData")
		int32 DEF;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "EnemyData")
		int32 Crit;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "EnemyData")
		TArray<FString> Abilities;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "EnemyData")
		int32 Gold;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "EnemyData")   
		int32 XP;

};