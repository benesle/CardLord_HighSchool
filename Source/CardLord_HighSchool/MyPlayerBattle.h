// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPlayerBattle.generated.h"

UCLASS()
class CARDLORD_HIGHSCHOOL_API AMyPlayerBattle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPlayerBattle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	void playerAttack();

	struct Attack
	{
		std::string name;
		int power;
		int accurancy;
	};

	struct Attack_Hit : public Attack
	{
		Attack_Hit()
		{
			name = "Hit";
			power = 30;
			accurancy = 95;
		}
	} hit;

	struct Attack_Kick : public Attack
	{
		Attack_Kick()
		{
		name = "Kick";
		power = 40;
		accurancy = 85;
		}
	}kick;

	struct Attack_Brace : public Attack
	{
		//Defencive move, takes less damage against enemy
		//Implement Hit reaction;
		Attack_Brace()
		{
			name = "Brace Yourself";
			power = 0;
			accurancy = 85;
		}
	} brace;

	struct Attack_Motivation : public Attack
	{
		//Defencive move 
		//Increase motivation
		Attack_Motivation()
		{
			name = "Motivational Speech";
			power = 0;
			accurancy = 90;
		}
	} motivate;

	
	struct AttackSlots : public Attack
	{
		AttackSlots(Attack, Attack, Attack, Attack)
		{
			Attack hit;
			Attack kick;
			Attack brace;
			Attack motivate;
		}

	};

	
};


