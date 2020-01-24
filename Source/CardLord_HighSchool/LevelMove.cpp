// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelMove.h"
#include "Components/CapsuleComponent.h"
#include "GameFrameWork/Actor.h"
#include "MyCharacter.h"
#include "Engine/EngineBaseTypes.h"


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
			AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
			if (MyCharacter->InBattleMode == true)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("OtherActor is %s"), *OtherActor->GetName()));
				StartPosition = OtherActor->GetActorLocation();
				
				UE_LOG(LogTemp, Warning, TEXT("%s Actor Vector"), *OtherActor->GetActorLocation().ToString());
				// Battle position is -500,-200 no elevation
				//OtherActor->SetActorLocation({ -500,-200,118.150 });
				GetWorld()->ServerTravel(FString("/Game/Maps/BattleMap"));
				//GetWorld()->SetGameMode(FURL("/Game/Gameplay/Blueprint/BP_BattleGameModeBase"));
				//UWorld* SetGame
				
				UE_LOG(LogTemp, Warning, TEXT("%s Actor Vector"), *StartPosition.ToString());
				UE_LOG(LogTemp, Warning, TEXT(" InBattleMode is %s"), (MyCharacter->InBattleMode ? TEXT("TRUE") : TEXT("FALSE")));
				
				

				MyCharacter->InBattleMode = true;
			}
			else if (MyCharacter->InBattleMode == false)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("OtherActor is %s"), *OtherActor->GetName()));
				//OtherActor->SetActorLocation(StartPosition);
				StartPosition = FVector{ 0,0,0 };
				
				GetWorld()->ServerTravel(FString("/Game/Maps/HighSchoolMap"));
				//GetWorld()->SetGameMode();

				UE_LOG(LogTemp, Warning, TEXT("%s Actor Vector"), *OtherActor->GetActorLocation().ToString());
				UE_LOG(LogTemp, Warning, TEXT("%s Actor Vector"), *StartPosition.ToString());
				UE_LOG(LogTemp, Warning, TEXT(" InBattleMode is %s"), (MyCharacter->InBattleMode ? TEXT("TRUE") : TEXT("FALSE")));
				MyCharacter->InBattleMode = false;

				if (UTransferStats* LoadedGame = Cast<UTransferStats>(UGameplayStatics::LoadGameFromSlot("ExportToBattle", 0)))
				{
					// The operation was successful, so LoadedGame now contains the data we saved earlier.
					UE_LOG(LogTemp, Warning, TEXT("LOADED: %s"), *LoadedGame->PlayerName);
					MyCharacter->Health = LoadedGame->TransferHealth;
					//UE_LOG(LogTemp, Warning, TEXT("LOADED: %f"), *MyCharacter->Health);
				}
				
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