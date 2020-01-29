// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Blueprint/WidgetLayoutLibrary.h"

AMyHUD::AMyHUD()
{
	GameplayHUDClass = nullptr;
	DeadClass = nullptr;
	PauseClass = nullptr;
	BattleHUDClass = nullptr;
}

bool AMyHUD::ShowSpesificMenu(TSubclassOf<class UUserWidget> ClassToShow, bool InGameOnly, bool ShowMouse)
{
	//Clear all UI elements 
	HideMenus();
	
	//Check if class to show is valid 
	if (ClassToShow)
	{
		//Create the Widget and then add it to the screen
		UUserWidget* CreatedWidget = CreateWidget<UUserWidget>(GetOwningPlayerController(), ClassToShow);
		CreatedWidget->AddToPlayerScreen();
	}

	//Check if we are in GameMode 
	if (InGameOnly)
	{
		//Set input mode to game, which allows full control of the player 
		GetOwningPlayerController()->SetInputMode(FInputModeGameOnly());
	}
	else
	{
		//Set input mode to UI only, this is usefull when we don't want the player to be able to move
		FInputModeUIOnly InputMode;
		//This allows the user to move the mouse out of the viewport, this is to not lock the mouse within the viewport
		InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		//Confirm input mode
		GetOwningPlayerController()->SetInputMode(InputMode);
	}

		//Update mouse cursor, Show mouse cursor  
		GetOwningPlayerController()->bShowMouseCursor = ShowMouse;

		//Exiting function
	return false;
}

void AMyHUD::HideMenus()
{
	//To call an already established function to remove all widget from the players screen
	UWidgetLayoutLibrary::RemoveAllWidgets(this);
}
