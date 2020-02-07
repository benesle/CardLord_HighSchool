// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Widgets/Views/SListView.h"
#include <Runtime\Slate\Public\Widgets\Views\SListView.h>
#include "MyPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class CARDLORD_HIGHSCHOOL_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	
	
};
