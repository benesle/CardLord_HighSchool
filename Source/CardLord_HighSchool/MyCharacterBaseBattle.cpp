// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterBaseBattle.h"
//#include "Kismet/HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MyHUD.h"
#include "Components/CapsuleComponent.h"
#include "CardLord_HighSchoolGameModeBase.h"
#include "Components/TextRenderComponent.h"


// Sets default values
AMyCharacterBaseBattle::AMyCharacterBaseBattle()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Players Health
	MaxHealth = 100.f;
	/*HPText = CreateDefaultSubobject<UTextRenderComponent>("My_HP");*/

	/*FullHealth = 100.0f;*/
	CurrentHealth = MaxHealth;
	MaxStamina = 100.f;
	CurrentStamina = MaxStamina;
	/*HealthPercentage = 1.0f;*/
	bCanBeDamaged = true;
	DamageAmount = 10;
	HudReference = nullptr;
}

//Pause and Unpause
void AMyCharacterBaseBattle::PauseGame()
{
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		// Check if we dont have a valid hud, edgecase
		if (!HudReference)
		{
			HudReference = Cast<AMyHUD>(PC->GetHUD());
		}

		// Checks if we now have a valid hud ref
		if (HudReference)
		{
			HudReference->ShowSpesificMenu(HudReference->GetPauseClass(), false, true);
		}

		// Pause the game
		PC->SetPause(true);
	}
}

void AMyCharacterBaseBattle::UnPauseGame()
{
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		// Unpause the game
		PC->SetPause(false);

		// Check if we dont have a valid hud, edgecase
		if (!HudReference)
		{
			HudReference = Cast<AMyHUD>(PC->GetHUD());
		}

		// Checks if we now have a valid hud ref
		if (HudReference)
		{
			HudReference->ShowSpesificMenu(HudReference->GetGameplayHUDClass(), true, false);
		}
	}
}

// Called when the game starts or when spawned
void AMyCharacterBaseBattle::BeginPlay()
{
	/*Super::BeginPlay();
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		ACardLord_HighSchoolGameModeBase* myGameMode = Cast<ACardLord_HighSchoolGameModeBase>(UGameplayStatics::GetGameMode(World));

	}
	*/
	/*HPText->SetText(FText::FromString(FString::Printf(TEXT("HP: %.1f"), HP)));*/
	
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

	// Assertion check
	check(PlayerInputComponent);

	// Attack input
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AMyCharacterBaseBattle::OnAttack);

}

void AMyCharacterBaseBattle::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Get and set our HUD reference
	if (APlayerController* PC = Cast<APlayerController>(NewController))
	{
		// Try and get a reference to the generic hud
		HudReference = Cast<AMyHUD>(PC->GetHUD());
		if (HudReference)
		{
			// If we successfully got the generic hud then show the gameplay hud
			HudReference->ShowSpesificMenu(HudReference->GetGameplayHUDClass(), true, false);
		}
	}
}

void AMyCharacterBaseBattle::OnDeath_Implementation()
{
	// Check if we dont have a valid hud, edgecase
	if (!HudReference)
	{
		// Get and set our HUD reference through the player controller
		if (APlayerController* PC = Cast<APlayerController>(GetController()))
		{
			HudReference = Cast<AMyHUD>(PC->GetHUD());
		}
	}

	// Checks if we now have a valid hud ref
	if (HudReference)
	{
		// Show the dead menu
		HudReference->ShowSpesificMenu(HudReference->GetDeadClass(), false, true);
	}
}

float AMyCharacterBaseBattle::TakeDamage(float DamageAmount)
{
	Super::TakeDamage(DamageAmount);

	// Don't continue if health is already below or at zero
	if (CurrentHealth <= 0.0f)
	{
		return 0.0f;
	}

	// Does the math for damaging the player
	const float SubtractedHealth = CurrentHealth - DamageAmount;

	// Check if the subtracted health is equal or lower than zero
	if (FMath::IsNearlyZero(SubtractedHealth) || SubtractedHealth < 0.0f)
	{
		// If it is then just lock it to zero and then call our OnDeath function
		CurrentHealth = 0.0f;
		OnDeath();
	}
	else
	{
		// Otherwise set the current health to the subtracted amount
		CurrentHealth = SubtractedHealth;
	}

	// Return the damaged amount of health
	return CurrentHealth;
}

//Interface Functions
//FString AMyCharacterBaseBattle::GetTestName()
//{
//	FString myName = this->GetTestName();
//	return myName;
//}


////Implementation of the react to player entered event 
//bool AMyCharacterBaseBattle::ReactToPlayerEntered_Implementation()
//{
//	/*HP = -100;
//	HPText->SetText(FText::FromString(FString::Printf(TEXT("HP: %.1f"), HP)));*/
//	return true;
//
//}



//float AMyCharacterBaseBattle::GetHealth()
//{
//	return HealthPercentage;
//}
//
//FText AMyCharacterBaseBattle::GetHealthIntText()
//{
//	int32 HP = FMath::RoundHalfFromZero(HealthPercentage * 100);
//	FString HPS = FString::FromInt(HP);
//	FString HealthHUD = HPS + FString(TEXT("%"));
//	FText HPText = FText::FromString(HealthHUD);
//	return HPText;
//}
//
//void AMyCharacterBaseBattle::UpdateHealth(float HealthChange)
//{
//	Health = FMath::Clamp(Health += HealthChange, 0.0f, FullHealth);
//	HealthPercentage = Health / FullHealth;
//}
