// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyItem.h"
#include "Components/CapsuleComponent.h"
#include "GameFrameWork/Actor.h"
#include "MyCharacter.h"
#include "Engine/EngineBaseTypes.h"

AKeyItem::AKeyItem() 
{
	OnActorBeginOverlap.AddDynamic(this, &AKeyItem::OnOverlapBegin);
}

void AKeyItem::BeginPlay()
{
	Super::BeginPlay();
}

void AKeyItem::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && OtherActor != this)
	{

		if (Cast<AMyCharacter>(OtherActor))
		{
			AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
			
			if (!MyCharacter->MathDefeated)
			{
				MyCharacter->MathDefeated = true;
				UE_LOG(LogTemp, Warning, TEXT("Math Defeated is true"));
				


			}
		}
	}
}
