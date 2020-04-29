//// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CardLord_HighSchool.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "FItemData.generated.h"


USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "ItemData")
		int32 HP;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "ItemData")
		int32 MP;


	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "ItemData")
		int32 ATK;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "ItemData")
		int32 DEF;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "ItemData")
		int32 Crit;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "ItemData")
		int32 Gold;

};