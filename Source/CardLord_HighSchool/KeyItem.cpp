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
			if (MyCharacter->MathDefeated)
			{
				MyCharacter->Inventory[MyCharacter->InventoryItems] = 5;

				MyCharacter->InventoryDescription[MyCharacter->InventoryItems] = "You have 6 items";
				UE_LOG(LogTemp, Warning, TEXT("Description is %s"), *MyCharacter->InventoryDescription[MyCharacter->InventoryItems]);
				MyCharacter->InventoryItems++;

			}
			if (!MyCharacter->MathDefeated)
			{
				MyCharacter->MathDefeated = true;
				UE_LOG(LogTemp, Warning, TEXT("Math Defeated is true"));
				


			}
		}
	}
}
