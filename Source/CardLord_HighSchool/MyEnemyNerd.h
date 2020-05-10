// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyEnemy.h"
#include "MyEnemyNerd.generated.h"

/**
 * 
 */
UCLASS()
class CARDLORD_HIGHSCHOOL_API AMyEnemyNerd : public APawn
{
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	AMyEnemyNerd();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	float distancePlayer;
	bool nearPlayer = false;
	bool attack = false;

	void Update();

	UFUNCTION()
		void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
		void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);


	FVector StartPosition = { 0,0,0 };
	FVector CameraPosition = { 0,0,0 };
	
};
