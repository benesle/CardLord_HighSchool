// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraTriggerBox.h"
#include "Components/BoxComponent.h"
#include "MyCharacter.h"
#include <iostream>
#include "GameFramework/SpringArmComponent.h"
// Sets default values
ACameraTriggerBox::ACameraTriggerBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	CollisionVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerVolume"));
	CollisionVolume->SetupAttachment(RootComponent);

	SetCameraRotation();

}

// Called when the game starts or when spawned
void ACameraTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &ACameraTriggerBox::OnOverlapBegin);
	CollisionVolume->OnComponentEndOverlap.AddDynamic(this, &ACameraTriggerBox::OnOverlapEnd);

	SetCameraRotation();
}

// Called every frame
void ACameraTriggerBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACameraTriggerBox::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (Cast<AMyCharacter>(OtherActor))
	{
		AMyCharacter* temp = Cast<AMyCharacter>(OtherActor);

		temp->CameraBoom->SetRelativeRotation(CameraRotation);
		temp->SavedCameraFvector = CameraRotation;
		temp->CameraSwitch = CameraSwitcher;
	
		
		bIsCharacterOverlapping = true;
		UE_LOG(LogTemp, Warning, TEXT("Overlapping character,CameraSwitch %d"), temp->CameraSwitch);
		WalkThrough = false;
		
	}
}

void ACameraTriggerBox::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	if (Cast<AMyCharacter>(OtherActor))
	{
		bIsCharacterOverlapping = false;
		UE_LOG(LogTemp, Warning, TEXT("End Overlapping character"));
		WalkThrough = true;

	}
		
}


void ACameraTriggerBox::SetCameraRotation()
{

	if (CameraSwitcher == 0 )
	{
		CameraRotation = FRotator(0, 90, 0);
	}
	else if (CameraSwitcher == 1)
	{
		CameraRotation = FRotator(0, 180, 0);
	}
	else if (CameraSwitcher == 2)
	{
		CameraRotation = FRotator(0, 270, 0);
	}
	else if (CameraSwitcher == 3 ) 
	{
		CameraRotation = FRotator(0, 0, 0);

	}
	
}

 

