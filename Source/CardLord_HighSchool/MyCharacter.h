// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS(config = Game)
class CARDLORD_HIGHSCHOOL_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	//Players current Health
	UFUNCTION(BlueprintCallable, Category = "Character|Health")
		void SetCurrentHealth(float NewHealth) { CurrentHealth = NewHealth; }

	UFUNCTION(BlueprintPure, Category = "Character|Health")
		float GetCurrentHealth() const { return CurrentHealth; }

	UFUNCTION(BlueprintPure, Category = "Character|Health")
		float GetMaxHealth() const { return MaxHealth; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Character|Death")
		void OnDeath();

	virtual void OnDeath_Implementation() PURE_VIRTUAL(AMyCharacter::OnDeath_Implementation, );

	float CurrentHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character|Health")
		float MaxHealth;



public:
	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* SideViewRotatedCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraRotatedBoom;

	//Movement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCharacter rotation movement")
		float CRotationRate = 540;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelSwitch")
		bool InBattleMode = false;

	int CameraSwitch = 0;
public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Handles input for moving forward and backward.
	UFUNCTION()
		void MoveForward(float Value);

	// Handles input for moving right and left.
	UFUNCTION()
		void MoveRight(float Value);
	
	UFUNCTION()
		void OnHit(AActor * SelfActor, AActor * OtherActor, FVector NormalImpulse, const FHitResult & Hit);

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewRotatedCameraComponent() const { return SideViewRotatedCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraRotatedBoom() const { return CameraRotatedBoom; }

	
	//bool InBattleMode = false;
	float Health = 100;
};
