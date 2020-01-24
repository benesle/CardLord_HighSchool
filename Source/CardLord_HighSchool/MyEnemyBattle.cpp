// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEnemyBattle.h"
#include "MyPlayerBattle.h"
#include "MyCharacter.h"
#include "DrawDebugHelpers.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Actor.h"

// Sets default values
AMyEnemyBattle::AMyEnemyBattle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

		OnActorHit.AddDynamic(this, &AMyEnemyBattle::OnHit);
		
		

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

		//Attack attacking;

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

void AMyEnemyBattle::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	//AMyCharacter Character;
/*	FColor DisplayColor = FColor::Yellow;
	const FString DebugMessage(OtherActor->GetName());
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, DisplayColor, DebugMessage); */

	if (OtherActor)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("%s has been hit"), *OtherActor->GetName()));
		if (OtherActor->IsA(AMyCharacter::StaticClass()))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("%s Is A static class cube"), *OtherActor->GetName()));
			AMyCharacter* Player = Cast<AMyCharacter>(OtherActor);

			if (UTransferStats* SaveGameInstance = Cast<UTransferStats>(UGameplayStatics::CreateSaveGameObject(UTransferStats::StaticClass())))
			{
				// Set data on the savegame object.
				SaveGameInstance->PlayerName = TEXT("PlayerOne");
				SaveGameInstance->TransferHealth = 90;
				UE_LOG(LogTemp, Warning, TEXT("%f health"), SaveGameInstance->TransferHealth);

				// Save the data immediately.
				if (UGameplayStatics::SaveGameToSlot(SaveGameInstance, "ExportToBattle", 0))
				{
					// Save succeeded.
				}
			}

			if (UTransferStats* LoadedGame = Cast<UTransferStats>(UGameplayStatics::LoadGameFromSlot("ExportToBattle", 0)))
			{
				// The operation was successful, so LoadedGame now contains the data we saved earlier.
				UE_LOG(LogTemp, Warning, TEXT("LOADED: %s"), *LoadedGame->PlayerName);
				//Player->Health = LoadedGame->TransferHealth;
				//UE_LOG(LogTemp, Warning, TEXT("LOADED: %f"), *MyCharacter->Health);
			}
			
			//AMyPlayerBattle *playerBattle;

			//playerBattle.DamageCharacter(power);

		}
		/*if (Cast<AMyCharacter>(OtherActor))
		{
			UE_LOG(LogTemp, Warning, TEXT("OtherActor Overlap Character"));

			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("OtherActor hitting cube"));
		}
		if (Cast<AMyCharacter>(SelfActor))
		{

			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlapped Overlap Person"));
		}*/
	}
}

float AMyEnemyBattle::DamageCharacter(float damage)
{
	return damage;
}
