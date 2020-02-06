// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleGameModeBase.h"
#include "Engine/World.h"
#include "CardLord_HighSchool.h"


ABattleGameModeBase::ABattleGameModeBase()
{
	
}

void ABattleGameModeBase::GetRenderedActors(TArray<AActor*>& CurrentlyRenderedActors, float MinRecentTime)
{
    //Empty any previous entries
    CurrentlyRenderedActors.Empty();

    //Iterate Over Actors
    for (TObjectIterator<AActor> Itr; Itr; ++Itr)
    {
        if (Itr->GetLastRenderTime() > MinRecentTime)
        {
            CurrentlyRenderedActors.Add(*Itr);
        }
    }
}