// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "GameCharacter.h"
#include "CombatManager.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "CombatUI.h"
#include "GymTeacherBattle.generated.h"

/**
 * 
 */
UCLASS()
class CARDLORD_HIGHSCHOOL_API AGymTeacherBattle : public AGameMode
{
	GENERATED_BODY()
	
        //virtual void StartPlay() override;


        virtual void BeginPlay() override;
    //Overrided tick function
    virtual void Tick(float DeltaTime) override;

    //virtual bool UpdateState(float Deltatime) override;

     //To test the combat system
    UFUNCTION(exec)
        void TestCombat();


public:
    AGymTeacherBattle(const class FObjectInitializer& ObjectInitializer);
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