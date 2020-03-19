// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "GameCharacter.h"
#include "CombatManager.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "CombatUI.h"
#include "BattleGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CARDLORD_HIGHSCHOOL_API ABattleGameMode : public AGameMode
{
	GENERATED_BODY()

   //Overrided tick function
   virtual void Tick(float DeltaTime) override;
   //virtual void StartPlay() override;
   ABattleGameMode(const class FObjectInitializer& ObjectInitializer);

public: 

	UPROPERTY()
		UCombatUI* CombatUIInstance;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
		TSubclassOf<class UCombatUI> CombatUIClass;

	//////Create new Widget Menu
	//UFUNCTION(Blueprintcallable, Category = "CombatUI")
	//void ChangeMenu(TSubclassOf<UUserWidget> NewMenuClass);

    //Combat manager instance
    CombatManager* currentCombatInstance;

    //Keep track of all the enemy characters
    TArray<UGameCharacter*> enemyGroup;

    //To test the combat system
    UFUNCTION(exec)
        void TestCombat();


protected:

 //   /** Called when the game starts. */
    virtual void BeginPlay() override;

 ////   /** The widget class we will use as our menu when the game starts. */
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CombatUI")
	//	TSubclassOf<UUserWidget> StartingMenuClass;

 ////   /** The widget instance that we are using as our menu. */
 //   UPROPERTY()
 //     UUserWidget* CurrentMenu;

};
