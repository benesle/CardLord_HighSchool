// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacterBaseBattle.generated.h"


UCLASS(config =Game)
class CARDLORD_HIGHSCHOOL_API AMyCharacterBaseBattle : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacterBaseBattle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//// Player Health
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Default")
	//	float Health1 = 1.0f;

	//// Player Mana
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mana Default")
	//	float Mana1 = 1.0f;

};
