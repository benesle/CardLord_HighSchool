// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelMove.h"
#include "Components/CapsuleComponent.h"
#include "GameFrameWork/Actor.h"
#include "MyCharacter.h"

ALevelMove::ALevelMove()
{
	OnActorBeginOverlap.AddDynamic(this, &ALevelMove::OnOverlapBegin);
}

void ALevelMove::BeginPlay()
{
	Super::BeginPlay();

	
}

void ALevelMove::OnOverlapBegin( AActor* OverlappedActor, AActor* OtherActor)
{
	// check if Actors do not equal nullptr and that 
	if (OtherActor && OtherActor != this)
	{

		if (Cast<AMyCharacter>(OtherActor))
		{
			if (StartPosition == FVector{0, 0, 0})
			{
				StartPosition = OtherActor->GetActorLocation();
				UE_LOG(LogTemp, Warning, TEXT("%s Actor Vector"), *OtherActor->GetActorLocation().ToString());
				OtherActor->SetActorLocation({ -500,-200,118.150 });
				UE_LOG(LogTemp, Warning, TEXT("%s Actor Vector"), *StartPosition.ToString());
			}
			else if (StartPosition != FVector{0, 0, 0})
			{
				OtherActor->SetActorLocation(StartPosition);
				StartPosition = FVector{ 0,0,0 };
				UE_LOG(LogTemp, Warning, TEXT("%s Actor Vector"), *OtherActor->GetActorLocation().ToString());
				UE_LOG(LogTemp, Warning, TEXT("%s Actor Vector"), *StartPosition.ToString());
				
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("CONFUSED!!!!!!!!!!"));
			}


			//GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, FString::Printf((TEXT("%s Overlap Character"), *OtherActor)));
			
		}
		if (Cast<AMyCharacter>(OverlappedActor))
		{

			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlapped Overlap Character"));
		}


		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Begin"));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("Overlapped Actor = %s"), *OverlappedActor->GetName()));

		}
	}
}