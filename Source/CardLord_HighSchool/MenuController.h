// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MenuController.generated.h"

/**
 * 
 */
UCLASS()
class CARDLORD_HIGHSCHOOL_API AMenuController : public APlayerController
{
	GENERATED_BODY()

public:

	/*AMenuController();*/
	virtual void BeginPlay() override;

	
};
