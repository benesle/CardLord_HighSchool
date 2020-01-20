// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEnemyBattle.h"

// Sets default values
AMyEnemyBattle::AMyEnemyBattle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyEnemyBattle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyEnemyBattle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyEnemyBattle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyEnemyBattle::RoundStart()
{
	//The Enemy will be agressive in battle untill it gets low HP
	//Enemy will then change state to defencive
	if (Health > 25)
	{
		stateDefensive = true;
		stateAgressive = false;
	}

	//If Enemy HP is over 50, the Enemy will then change state to defensive
	if (Health > 50)
	{
		stateDefensive = false;
		stateAgressive = true;
	}
}

void AMyEnemyBattle::Update()
{
}

void AMyEnemyBattle::Defensive()
{
	//Use defensive moves
	//Use healing items
}

void AMyEnemyBattle::Agressive()
{
	//Use attack moves 
	//Use DOTS
}

