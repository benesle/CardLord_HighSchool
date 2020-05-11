// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "MyEnemyBattle.h"
#include "MyEnemy.h"
#include "DT_CharacterActionTypeData.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"

// Sets default values
AMyCharacter::AMyCharacter()
{

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	//OnActorHit.AddDynamic(this, &AMyCharacter::OnHit);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f, 0.f, 75.f);
	CameraBoom->SetRelativeRotation(FRotator(0.f, 180.f, 0.f));

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Create another camera boom attached to the root (capsule)
	CameraRotatedBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraRotatedBoom"));
	CameraRotatedBoom->SetupAttachment(RootComponent);
	CameraRotatedBoom->SetUsingAbsoluteRotation(true); // Rotation of the character should not affect rotation of boom
	CameraRotatedBoom->bDoCollisionTest = false;
	CameraRotatedBoom->TargetArmLength = 500.f;
	CameraRotatedBoom->SocketOffset = FVector(0.f, 0.f, 75.f);
	CameraRotatedBoom->SetRelativeRotation(FRotator(0.f, 180.f, 0.f));

	// Create a camera and attach to boom
	SideViewRotatedCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewRotatedCamera"));
	SideViewRotatedCameraComponent->SetupAttachment(CameraRotatedBoom, USpringArmComponent::SocketName);
	SideViewRotatedCameraComponent->bUsePawnControlRotation = false; // Again we don't want the controller rotating the camera

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, CRotationRate, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (DataTable != NULL)
	{
		FCharacterActionTypeData* row = DataTable->FindRow<FCharacterActionTypeData>(TEXT("Attack_Hit"), TEXT(" LookupCharacterActionType"));
		FString ActionType = row->ActionType;
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ActionType);
	}
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	/*Super::SetupPlayerInputComponent(PlayerInputComponent);*/

	// Set up "movement" bindings.
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);

}

void AMyCharacter::MoveForward(float Value)
{
	//Fire caser i forhold til rotasjonen på kameraet
	if (CameraSwitch == 0)
	{//0  //Da er CameraRotation = 90 -> Normal

		// Find out which way is "forward" and record that the player wants to move that way.
		FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
		//UE_LOG(LogTemp, Warning, TEXT("MoveForward 0"));
	}
	else if (CameraSwitch == 1)
	{	//1 CameraRoation = 180 
		FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, -Value);
		//UE_LOG(LogTemp, Warning, TEXT("MoveForward 1"));

	}
	else if (CameraSwitch == 2)
	{
		//2 CameraRotation = 270

	//	// Find out which way is "forward" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);

	// add movement in that direction
	AddMovementInput(Direction, -Value);
	}

	//3 CameraRotation = 0

	else if (CameraSwitch == 3)
	{
		FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}


	//// Find out which way is "forward" and record that the player wants to move that way.
	//FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);

	//// add movement in that direction
	//AddMovementInput(Direction, Value);
}

void AMyCharacter::MoveRight(float Value)
{

	//Fire caser i forhold til rotasjonen på kameraet
	if (CameraSwitch == 0)
	{//0  //Da er CameraRotation = 90 -> Normal

		// Find out which way is "forward" and record that the player wants to move that way.
		FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
		// add movement in that direction
		AddMovementInput(Direction, Value);
		//UE_LOG(LogTemp, Warning, TEXT("MoveRight 0"));
	}
	else if (CameraSwitch == 1)
	{	//1 CameraRoation = 180 
		FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
		//UE_LOG(LogTemp, Warning, TEXT("MoveRight 1"));

	}
	else if (CameraSwitch == 2)
	{
		//2 CameraRotation = 270

	//	// Find out which way is "forward" and record that the player wants to move that way.
		FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);

		// add movement in that direction
		AddMovementInput(Direction, -Value);
	}

	//3 CameraRotation = 0

	else if (CameraSwitch == 3)
	{
		FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, -Value);
	}


	//// Find out which way is "right" and record that the player wants to move that way.
	//FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	//AddMovementInput(Direction, Value);

	////AddMovementInput(FVector(0.f, -1.f, 0.f), Value);


}

void AMyCharacter::SavedCameraRotation()
{
	CameraBoom->SetRelativeRotation(SavedCameraFvector);
}

void AMyCharacter::OnHit(AActor * SelfActor, AActor * OtherActor, FVector NormalImpulse, const FHitResult & Hit)
{
	
	if (OtherActor)
	{
		if (Cast<AMyEnemyBattle>(OtherActor))
		{
			/*if (Health > 0) 
			{
				AMyEnemyBattle* NewEnemy = Cast<AMyEnemyBattle>(OtherActor);
				Health = Health - NewEnemy->DamageCharacter(10);
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("%f BOXY BOX"), AMyCharacter::Health));
				UE_LOG(LogTemp, Warning, TEXT("%f Overlap Character"), Health);*/

				GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("OtherActor Overlap Character"));
			}
			else
			{
				return;
			}
		}
		if (Cast<AMyEnemyBattle>(SelfActor))
		{

			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlapped Overlap Character"));
		}
		
		/*if (Cast<AMyEnemy>(OtherActor) )
		{
			AMyCharacter* MyCharacter = Cast<AMyCharacter>(SelfActor);
			if (MyCharacter->InBattleMode == true)
			{
				UE_LOG(LogTemp, Warning, TEXT("%s Actor Vector"), *OtherActor->GetActorLocation().ToString());
				GetWorld()->ServerTravel(FString("/Game/Maps/Battle"));

				MyCharacter->InBattleMode = true;
			}
			else if (MyCharacter->InBattleMode == false)
			{
				GetWorld()->ServerTravel(FString("/Game/Maps/HighSchoolMap"));
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("CONFUSED!!!!!!!!!!"));
			}
			
			
		}*/
	}

//ReactToBattlemode activated 
//bool AMyCharacter::ReactToBattleEntered_Implementation()
//{
//	GEngine->AddOnScreenDebugMessage(-2, 2, FColor::Green,
//	FString::Printf(TEXT("BattleMode activated")));
//	return true;
//}