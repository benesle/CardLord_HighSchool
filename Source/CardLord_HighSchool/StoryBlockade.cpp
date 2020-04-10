// Fill out your copyright notice in the Description page of Project Settings.


#include "StoryBlockade.h"
#include "Components/CapsuleComponent.h"
#include "GameFrameWork/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "MyCharacter.h"
#include "Engine/EngineBaseTypes.h"

AStoryBlockade::AStoryBlockade()
{
	OnActorBeginOverlap.AddDynamic(this, &AStoryBlockade::OnOverlapBegin);
}

void AStoryBlockade::BeginPlay()
{
	Super::BeginPlay();
}

void AStoryBlockade::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && OtherActor != this)
	{

		if (Cast<AMyCharacter>(OtherActor))
		{
			AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
			if (MyCharacter->Inventory[3] == 1)
			{
				FVector OriginalPlace = this->GetActorLocation();
				OriginalPlace.X = OriginalPlace.X + 100;
				this->SetActorLocation(OriginalPlace);
			}
			else if (MyCharacter->InventoryItems < 50)
			{

				UE_LOG(LogTemp, Warning, TEXT("You are not allowed here, get the key item"));



			}
		}
	}
}