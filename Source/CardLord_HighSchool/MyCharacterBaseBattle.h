// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.h"
#include "MyCharacterBaseBattle.generated.h"

//class UTextRenderComponent;

//UPROPERTY()


UCLASS(config = Game)
class CARDLORD_HIGHSCHOOL_API AMyCharacterBaseBattle : public AMyCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacterBaseBattle();
	int CurrentStamina;


protected:
	AMyCharacterBaseBattle();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnDeath_Implementation() override;
	virtual float TakeDamage(float DamageAmount);
	bool bCanBeDamaged = true;

	UFUNCTION(BlueprintCallable, Category = "Character|Input")
		void PauseGame();

	UFUNCTION(BlueprintCallable, Category = "Character|Input")
		void UnPauseGame();

	//Attack moves 
	//Declare a function that must be Implemented in C++
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Character|Attack")
	/*void OnAttack(); 
	virtual void OnAttack_Implementation();*/

	//Check if more Stamina

	bool HasStamina() const { return (CurrentStamina > 0); }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Attack")
		bool bCanAttack;

	UPROPERTY(BlueprintPure, Category = "Character|Attack")
		float DamageAmount;

	UFUNCTION(BlueprintPure, Category = "Character|Attack")
		int32 GetCurrentStamina() const { CurrentStamina; }

	UFUNCTION(BlueprintPure, Category = "Character|Gun|Ammo")
		int32 GetMaxStamina() const { return MaxStamina; }

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character|Gun|Ammo")
		int MaxStamina;


	//Check if has money
	int CurrentMoney;
	bool HasMoney() const { return (CurrentMoney > 0); }

	////Players Health
	//bool IsAlive() const { return(CurrentHealth > 0); }
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Health")
	//float HealtValue;
	
	//float Health;
	//UTextRenderComponent* HPText;
private:
	UPROPERTY()
	class AMyHUD* HudReference;


	//Declare a function that must be Implemented in C++
	/*UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category= "Interfaces")*/
	//bool ReactToPlayerEntered();


	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	//	float FullHealth;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	//	float Health;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	//	float HealthPercentage;

	///** Get Health */
	//UFUNCTION(BlueprintPure, Category = "Health")
	//	float GetHealth();

	///** Get Health Text */
	//UFUNCTION(BlueprintPure, Category = "Health")
	//	FText GetHealthIntText();

	//UFUNCTION(BlueprintCallable, Category = "Power")
	//	void UpdateHealth(float HealthChange);


	//// Player Health
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Default")
	//	float Health1 = 1.0f;

	//// Player Mana
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mana Default")
	//	float Mana1 = 1.0f;

};
