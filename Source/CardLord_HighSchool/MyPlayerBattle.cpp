// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerBattle.h"
#include "Widget.h"
#include "BattleGameMode.h"
#include "MyEnemyBattle.h"
#include "MyPlayerController.h"
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
	ReactToBattleEntered();
	
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


void AMyPlayerBattle::StopPlayerMovement(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent = nullptr;
}

//Implementation of the react to player entered the battle event
bool AMyPlayerBattle::ReactToBattleEntered_Implementation()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	this->DisableInput(PlayerController);
	Health = 1.0f;
	GEngine->AddOnScreenDebugMessage(-2, 2, FColor::Green,
		FString::Printf(TEXT("Player Entered Battle") ));
	SetActorLocation(FVector(40.0, 50.0f, 100.0f));
	//GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_None);
	return true;
	//Test
}

void AMyPlayerBattle::PlayerHit(AActor* OtherActor, float DamageDone, float ManaCost, float DamageTaken)
{
	//Health = 1.0f;
	if(OtherActor)
	{
		if (Cast<AMyEnemyBattle>(OtherActor))
		{
			if (Mana < 0)
			{
				Mana = 0;
			}
			if (Mana >= ManaCost)
			{
				AMyEnemyBattle* Target = Cast<AMyEnemyBattle>(OtherActor);
				Target->EnemyHealth -= DamageDone;
				Health -= Target->DamageCharacter(DamageTaken);
				Mana -= ManaCost;

				if (Target->EnemyHealth < 0)
				{
					EXPGained = 701;
					if (EXPGained > ExpToNextLevel)
					{
						levelup(ExpToNextLevel, EXPGained);
					}
					else {
						EXPGained -= ExpToNextLevel;
					}
					//UE_LOG(LogTemp, Warning, TEXT("%f EXP to next level"), ExpToNextLevel);
				}
			}

			
			
		}
	}
}

void AMyPlayerBattle::PlayerHeal(AActor* OtherActor, float DamageHealed, float ManaCost, float DamageTaken)
{
	//Health = 1.0f;
	if (OtherActor)
	{
		if (Cast<AMyEnemyBattle>(OtherActor))
		{
			if (Mana < 0)
			{
				Mana = 0;
			}
			if (Mana >= ManaCost)
			{
				AMyEnemyBattle* Target = Cast<AMyEnemyBattle>(OtherActor);
				Health += DamageHealed;
				if (Health > 1.0f) 
				{
					Health = 1.0f;
				}
				Health -= Target->DamageCharacter(DamageTaken);
				Mana -= ManaCost;
			}

		}
	}
}

void AMyPlayerBattle::levelup(float toNext, float gained)
{
	do
	{
		float OriginalExpToNextLevel = toNext;
		CharacterLevel++;
		gained -= toNext;
		toNext = OriginalExpToNextLevel * 2;
		UE_LOG(LogTemp, Warning, TEXT("%f EXP to next level"), toNext);
		UE_LOG(LogTemp, Warning, TEXT("%f EXP to next level"), gained);
	} while (gained > toNext);
	UE_LOG(LogTemp, Warning, TEXT("%f Current Level"), CharacterLevel);
}