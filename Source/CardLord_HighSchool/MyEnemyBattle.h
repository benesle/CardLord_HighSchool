// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <string>
#include "TransferStats.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
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

	
	UFUNCTION()
		void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

	

	//structs
	
	struct Attack {
		std::string name;
		int power;
		int accuracy;
	}; // Attack slots

	struct Attack_Bash : public Attack 
	{
		Attack_Bash() {
			name = "Bash";
			power = 30;
			accuracy = 100;
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Initialized function"));
			}
		}
	}Bash;
	
	float power = 90;

	float DamageCharacter(float damage);

};
