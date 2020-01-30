// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleGameMode.h"



void ABattleGameMode::BeginPlay()
{
    Super::BeginPlay();
		ChangeMenu(StartingMenuClass);
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