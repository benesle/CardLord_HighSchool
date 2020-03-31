// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerBox.h"
// include draw debu helpers header file
#include "DrawDebugHelpers.h"
#include "MyCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"

//AMyTriggerBox::AMyTriggerBox()
//{
//    //Register Events
//    OnActorBeginOverlap.AddDynamic(this, &AMyTriggerBox::OnOverlapBegin);
//    OnActorEndOverlap.AddDynamic(this, &AMyTriggerBox::OnOverlapEnd);
//}
//
//// Called when the game starts or when spawned
//void AMyTriggerBox::BeginPlay()
//{
//    Super::BeginPlay();
//
//    DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, 999, 0, 5);
//}
//
//void AMyTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
//{
//    // check if Actors do not equal nullptr and that 
//    if (OtherActor && OtherActor != this)
//    {
//
//		if (Cast<AMyCharacter>(OtherActor))
//		{
//			UE_LOG(LogTemp, Warning, TEXT("OtherActor Overlap Character"));
//
//			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("OtherActor Overlap Character"));
//		}
//		if (Cast<AMyCharacter>(OverlappedActor))
//		{
//			
//			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlapped Overlap Character"));
//		}
//
//
//        if (GEngine)
//        {
//            GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Begin"));
//            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("Overlapped Actor = %s"), *OverlappedActor->GetName()));
//            
//        }
//    }
//}
//
//void AMyTriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
//{
//    if (OtherActor && OtherActor != this)
//    {
//        if (GEngine)
//        {
//            GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Ended"));
//            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("%s has left the Trigger Box"), *OtherActor->GetName()));
//            
//        }
//    }
//}