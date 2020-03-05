// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyCharacter.h"
#include "MyInterface.h"
#include "MyPlayerBattle.generated.h"

UCLASS()
class CARDLORD_HIGHSCHOOL_API AMyPlayerBattle : public AMyCharacter
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

	

	//Player healthbar default value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health|Default")
	float Health;

	//Player manabar default value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mana|Default")
	float Mana;

	//Player Level
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Levels|Level")
		float CharacterLevel;

	//Player Exp to next Level
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Levels|Exp")
		float ExpToNextLevel;

	//EXP gained at current level
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Levels|Exp")
		float EXPGained;

	//Connect the UI to the player
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interface")
	bool ReactToBattleEntered();

	UFUNCTION(BlueprintCallable)
	void PlayerHit(AActor* OtherActor, float DamageDone, float ManaCost, float DamageTaken);

	UFUNCTION(BlueprintCallable)
		void PlayerHeal(AActor* OtherActor, float DamageHealed, float ManaCost, float DamageTaken);

	void levelup(float toNext, float gained);
	
	
	//bool ReactToBattleEntered_Implementation(UInputComponent* PlayerInputComponent);
	//To override the base funtionallity of the interface
	virtual bool ReactToBattleEntered_Implementation() override;

	

	void StopPlayerMovement(UInputComponent* PlayerInputComponent);
	//UPROPERTY()
		//class A*/


	//
	//void playerAttack();

	//struct Attack
	//{
	//	std::string name;
	//	int power;
	//	int accurancy;
	//};

	//struct Attack_Hit : public Attack
	//{
	//	Attack_Hit()
	//	{
	//		name = "Hit";
	//		power = 30;
	//		accurancy = 95;
	//	}
	//} hit;

	//struct Attack_Kick : public Attack
	//{
	//	Attack_Kick()
	//	{
	//	name = "Kick";
	//	power = 40;
	//	accurancy = 85;
	//	}
	//}kick;

	//struct Attack_Brace : public Attack
	//{
	//	//Defencive move, takes less damage against enemy
	//	//Implement Hit reaction;
	//	Attack_Brace()
	//	{
	//		name = "Brace Yourself";
	//		power = 0;
	//		accurancy = 85;
	//	}
	//} brace;

	//struct Attack_Motivation : public Attack
	//{
	//	//Defencive move 
	//	//Increase motivation
	//	Attack_Motivation()
	//	{
	//		name = "Motivational Speech";
	//		power = 0;
	//		accurancy = 90;
	//	}
	//} motivate;

	//
	//struct AttackSlots : public Attack
	//{
	//	AttackSlots(Attack, Attack, Attack, Attack)
	//	{
	//		Attack hit;
	//		Attack kick;
	//		Attack brace;
	//		Attack motivate;
	//	}

	//};

	
};


