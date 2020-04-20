// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CardLord_HighSchoolGameModeBase.generated.h"


UCLASS()
class CARDLORD_HIGHSCHOOL_API ACardLord_HighSchoolGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

		ACardLord_HighSchoolGameModeBase(const class FObjectInitializer& ObjectInitializer);

public:
		virtual void StartPlay() override;
	
};
