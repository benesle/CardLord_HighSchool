// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerBattle.h"
#include "DrawDebugHelpers.h"

// Sets default values
AMyPlayerBattle::AMyPlayerBattle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPlayerBattle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPlayerBattle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayerBattle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//void AMyPlayerBattle::playerAttack()
//{
//	AttackSlots playerAttackSlots(hit, kick, brace, motivate);
//	
//}




