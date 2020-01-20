// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyEnemyBattle.generated.h"

UCLASS()
class CARDLORD_HIGHSCHOOL_API AMyEnemyBattle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyEnemyBattle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	int Health = 100;
	int Stamina = 100;
	bool stateAgressive;
	bool stateDefensive;

	//Initialisation
	void RoundStart();
	void Update();

	//States
	void Defensive();
	void Agressive();



};
