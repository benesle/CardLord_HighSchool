// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterBaseBattle.h"
#include "Kismet/HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "CardLord_HighSchoolGameModeBase.h"
#include "Components/TextRenderComponent.h"


// Sets default values
AMyCharacterBaseBattle::AMyCharacterBaseBattle()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Players Health
	HP = 100.f;
	HPText = CreateDefaultSubobject<UTextRenderComponent>("My_HP");

	FullHealth = 100.0f;
	Health = FullHealth;
	HealthPercentage = 1.0f;
	bCanBeDamaged = true;

}

// Called when the game starts or when spawned
void AMyCharacterBaseBattle::BeginPlay()
{
	Super::BeginPlay();
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		ACardLord_HighSchoolGameModeBase* myGameMode = Cast<ACardLord_HighSchoolGameModeBase>(UGameplayStatics::GetGameMode(World));

	}
	
	HPText->SetText(FText::FromString(FString::Printf(TEXT("HP: %.1f"), HP)));
	
}

// Called every frame
void AMyCharacterBaseBattle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacterBaseBattle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//Interface Functions
FString AMyCharacterBaseBattle::GetTestName()
{
	FString myName = this->GetTestName();
	return myName;
}


////Implementation of the react to player entered event 
bool AMyCharacterBaseBattle::ReactToPlayerEntered_Implementation()
{
	HP = -100;
	HPText->SetText(FText::FromString(FString::Printf(TEXT("HP: %.1f"), HP)));
	return true;

}

float AMyCharacterBaseBattle::GetHealth()
{
	return HealthPercentage;
}

FText AMyCharacterBaseBattle::GetHealthIntText()
{
	int32 HP = FMath::RoundHalfFromZero(HealthPercentage * 100);
	FString HPS = FString::FromInt(HP);
	FString HealthHUD = HPS + FString(TEXT("%"));
	FText HPText = FText::FromString(HealthHUD);
	return HPText;
}

void AMyCharacterBaseBattle::UpdateHealth(float HealthChange)
{
	Health = FMath::Clamp(Health += HealthChange, 0.0f, FullHealth);
	HealthPercentage = Health / FullHealth;
}
