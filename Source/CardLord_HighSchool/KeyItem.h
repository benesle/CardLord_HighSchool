// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Kismet/GameplayStatics.h"
#include "KeyItem.generated.h"

/**
 * 
 */
UCLASS()
class CARDLORD_HIGHSCHOOL_API AKeyItem : public ATriggerBox
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//Notification event for when Player and enemy collide 
	void NotifyPlayerOverlap(AActor* otherActor);

public:
	// constructor sets default values for this actor's properties
	AKeyItem();

	// overlap begin function
	UFUNCTION()
		void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);

	FVector StartPosition = { 0,0,0 };
	FVector CameraPosition = { 0,0,0 };

	//Decleration of BattleEvent
	DECLARE_EVENT(ALevelMove, FBattleStart)
	FBattleStart OnBattleLevelEntered;


	
};
