// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleGameMode.h"
#include "MyPlayerBattle.h"
#include "MyPlayerController.h"



void ABattleGameMode::BeginPlay()
{
    Super::BeginPlay();
		ChangeMenu(StartingMenuClass);

        DefaultPawnClass = AMyPlayerBattle::StaticClass();
        PlayerControllerClass = AMyPlayerController::StaticClass();
}

void ABattleGameMode::ChangeMenu(TSubclassOf<UUserWidget> NewMenuClass)
{
    if (CurrentMenu != nullptr)
    {
        CurrentMenu->RemoveFromViewport();
        CurrentMenu = nullptr;
    }
    if (NewMenuClass != nullptr)
    {
        CurrentMenu = CreateWidget<UUserWidget>(GetWorld(), NewMenuClass);
        if (CurrentMenu != nullptr)
        {
            CurrentMenu->AddToViewport();
        }
    }
}

