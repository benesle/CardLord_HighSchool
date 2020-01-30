// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "BattleGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CARDLORD_HIGHSCHOOL_API ABattleGameMode : public AGameModeBase
{
	GENERATED_BODY()

public: 
	//Create new Widget Menu
	UFUNCTION(Blueprintcallable, Category = "BattleHUD")
		void ChangeMenu(TSubclassOf<UUserWidget> NewMenuClass);

protected:

    /** Called when the game starts. */
    virtual void BeginPlay() override;

    /** The widget class we will use as our menu when the game starts. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BattleHUD")
        TSubclassOf<UUserWidget> StartingMenuClass;

    /** The widget instance that we are using as our menu. */
    UPROPERTY()
        UUserWidget* CurrentMenu;

};
