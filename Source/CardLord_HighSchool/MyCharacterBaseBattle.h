// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CombatUserInterface.h"
#include "MyCharacterBaseBattle.generated.h"

class UTextRenderComponent;

UCLASS(config = Game)
class CARDLORD_HIGHSCHOOL_API AMyCharacterBaseBattle : public ACharacter, public ICombatUserInterface
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

	//Players Health
	float HP;
	UTextRenderComponent* HPText;

	//Declare the override of the Interface
	FString GetTestName() override;

	//Declare a function that must be Implemented in C++
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category= "Interfaces")
	bool ReactToPlayerEntered();

	virtual bool ReactToPlayerEntered_Implementation() override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float FullHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float HealthPercentage;

	/** Get Health */
	UFUNCTION(BlueprintPure, Category = "Health")
		float GetHealth();

	/** Get Health Text */
	UFUNCTION(BlueprintPure, Category = "Health")
		FText GetHealthIntText();

	UFUNCTION(BlueprintCallable, Category = "Power")
		void UpdateHealth(float HealthChange);


	//// Player Health
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Default")
	//	float Health1 = 1.0f;

	//// Player Mana
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mana Default")
	//	float Mana1 = 1.0f;

};
