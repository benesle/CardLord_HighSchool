// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "LevelMove.generated.h"

/**
 * 
 */
UCLASS()
class CARDLORD_HIGHSCHOOL_API ALevelMove : public ATriggerBox
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// constructor sets default values for this actor's properties
	ALevelMove();

	// overlap begin function
	UFUNCTION()
		void OnOverlapBegin( AActor* OverlappedActor, AActor* OtherActor);

	FVector StartPosition = { 0,0,0 };
	FVector CameraPosition = { 0,0,0 };

	//bool InBattleMode = true;

};
