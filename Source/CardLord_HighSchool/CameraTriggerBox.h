// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraTriggerBox.generated.h"

UCLASS()
class CARDLORD_HIGHSCHOOL_API ACameraTriggerBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraTriggerBox();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* CollisionVolume;


	bool bIsCharacterOverlapping = false;
	//Denne skal ikke endres, SetCameraRotation gjør det. 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FRotator CameraRotation = FRotator(0, 0, 90);
	//Min 0, Max 3
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CameraSwitcher = 0;
	bool WalkThrough = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/** called when something leaves the sphere component */
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	void SetCameraRotation();
};
