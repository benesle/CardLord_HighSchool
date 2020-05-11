// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BattleGameMode.h"
#include "GameCharacter.h"
#include "CombatManager.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "CombatUI.h"
#include "NerdGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CARDLORD_HIGHSCHOOL_API ANerdGameMode : public AGameMode//ABattleGameMode
{
	GENERATED_BODY()
	
        //virtual void StartPlay() override;
        ANerdGameMode(const class FObjectInitializer& ObjectInitializer);

    virtual void BeginPlay() override;
    //Overrided tick function
    virtual void Tick(float DeltaTime) override;

		UFUNCTION(exec)
		void TestNerdCombat();

public:

    //Combat manager instance
    CombatManager* currentCombatInstance;

    //An array with all the enemy group members 
    TArray<UGameCharacter*> enemyGroup;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
        TSubclassOf<class UUserWidget> GameOverClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
        TSubclassOf<class UCombatUI> CombatUIClass;

    UPROPERTY()
        UCombatUI* CombatUIInstance;

};
