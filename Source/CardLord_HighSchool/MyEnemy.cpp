// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEnemy.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "CardLordGameInstance.h"
#include "FEnemyData.h"
#include "MyCharacter.h"

// Sets default values
AMyEnemy::AMyEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OnActorHit.AddDynamic(this, &AMyEnemy::OnHit);
	OnActorBeginOverlap.AddDynamic(this, &AMyEnemy::OnOverlapBegin);

}

// Called when the game starts or when spawned
void AMyEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyEnemy::Update()
{
	if (distancePlayer < 0.1f)
	{
		nearPlayer = true;
		attack = true;
	}
	else
	{
		nearPlayer = false;
		attack = false;
	}
}


void AMyEnemy::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("%s Actor Vector"), *OtherActor->GetActorLocation().ToString());	// check if Actors do not equal nullptr and that 
	if (OtherActor && OtherActor != this)
	{

		if (Cast<AMyCharacter>(OtherActor))
		{
				AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
				if (MyCharacter->InBattleMode == true)
				{
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("OtherActor is %s"), *OtherActor->GetName()));
					//StartPosition = OtherActor->GetActorLocation();

					UE_LOG(LogTemp, Warning, TEXT("%s Actor Vector"), *OtherActor->GetActorLocation().ToString());
					// Battle position is -500,-200 no elevation
					OtherActor->SetActorLocation({ -500,-200,118.150 });
					GetWorld()->ServerTravel(FString("/Game/Maps/Battle"));

				
					//GetWorld()->SetGameMode(FURL("/Game/Gameplay/Blueprint/BP_BattleGameModeBase"));
					//UWorld* SetGame

					//UE_LOG(LogTemp, Warning, TEXT("%s Actor Vector"), *StartPosition.ToString());
					UE_LOG(LogTemp, Warning, TEXT(" InBattleMode is %s"), (MyCharacter->InBattleMode ? TEXT("TRUE") : TEXT("FALSE")));



					MyCharacter->InBattleMode = true;
				}
				else if (MyCharacter->InBattleMode == false)
				{
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("OtherActor is %s"), *OtherActor->GetName()));
					//OtherActor->SetActorLocation(StartPosition);
					//StartPosition = FVector{ 0,0,0 };

					GetWorld()->ServerTravel(FString("/Game/Maps/Floor_1"));
					//GetWorld()->SetGameMode();

					UE_LOG(LogTemp, Warning, TEXT("%s Actor Vector"), *OtherActor->GetActorLocation().ToString());
					UE_LOG(LogTemp, Warning, TEXT("%s Actor Vector"), *StartPosition.ToString());
					UE_LOG(LogTemp, Warning, TEXT(" InBattleMode is %s"), (MyCharacter->InBattleMode ? TEXT("TRUE") : TEXT("FALSE")));
					MyCharacter->InBattleMode = false;

					/*if (UTransferStats* LoadedGame = Cast<UTransferStats>(UGameplayStatics::LoadGameFromSlot("ExportToBattle", 0)))
					{
						// The operation was successful, so LoadedGame now contains the data we saved earlier.
						UE_LOG(LogTemp, Warning, TEXT("LOADED: %s"), *LoadedGame->PlayerName);
						MyCharacter->Health = LoadedGame->TransferHealth;
						//UE_LOG(LogTemp, Warning, TEXT("LOADED: %f"), *MyCharacter->Health);
					}*/

				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("CONFUSED!!!!!!!!!!"));
				}


			//GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, FString::Printf((TEXT("%s Overlap Character"), *OtherActor)));

		}
		if (Cast<AMyCharacter>(SelfActor))
		{

			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlapped Overlap Character"));
		}


		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Begin"));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("Overlapped Actor = %s"), *SelfActor->GetName()));

		}
	}
}

void AMyEnemy::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlapped begin"));
	 //check if Actors do not equal nullptr and that 
	if (OtherActor && OtherActor != this)
	{

		if (Cast<AMyCharacter>(OtherActor))
		{
			AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
			if (MyCharacter->InBattleMode == true)
			{
				//if (UTransferStats* SaveGameInstance = Cast<UTransferStats>(UGameplayStatics::CreateSaveGameObject(UTransferStats::StaticClass())))
				//if(UGameInstance* gameInstance = Cast<UCardLordGameInstance>(UGameplayStatics::CreateSaveGameObject(UCardLordGameInstance::StaticClass())))
				//{
					// Set up the (optional) delegate.
					//FAsyncSaveGameToSlotDelegate SavedDelegate;
					// USomeUObjectClass::SaveGameDelegateFunction is a void function that takes the following parameters: const FString& SlotName, const int32 UserIndex, bool bSuccess
					//SavedDelegate.BindUObject(SomeUObjectPointer, &USomeUObjectClass::SaveGameDelegateFunction);

					// Set data on the savegame object.
			
					//SaveGameInstance->PlayerName = TEXT("PlayerOne");
					

					// Start async save process.
					//UGameplayStatics::AsyncSaveGameToSlot(SaveGameInstance, "OverWorld", 0, SavedDelegate);
					//UGameplayStatics::

				//}
				StartPosition = OtherActor->GetActorLocation();
				GetWorld()->ServerTravel(FString("/Game/Maps/Battle"));

				MyCharacter->InBattleMode = true;
			}
			else if (MyCharacter->InBattleMode == false)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("OtherActor is %s"), *OtherActor->GetName()));
				OtherActor->SetActorLocation(StartPosition);
				StartPosition = FVector{ 0,0,0 };
				//Need to check if map exists!
				GetWorld()->ServerTravel(FString("/Game/Maps/Floor_1.Floor_1"));

				UE_LOG(LogTemp, Warning, TEXT("%s Actor Vector"), *OtherActor->GetActorLocation().ToString());
				UE_LOG(LogTemp, Warning, TEXT("%s Actor Vector"), *StartPosition.ToString());
				UE_LOG(LogTemp, Warning, TEXT(" InBattleMode is %s"), (MyCharacter->InBattleMode ? TEXT("TRUE") : TEXT("FALSE")));
				MyCharacter->InBattleMode = false;
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