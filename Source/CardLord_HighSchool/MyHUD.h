// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class CARDLORD_HIGHSCHOOL_API AMyHUD : public AHUD
{
	GENERATED_BODY()



public:

	//Constructor
	AMyHUD();

	class TSubclassOf<UUserWidget> GetGameplayHUDClass() const { return GameplayHUDClass; }
	class TSubclassOf<UUserWidget> GetDeadClass() const { return DeadClass; }
	class TSubclassOf<UUserWidget> GetPauseClass() const { return PauseClass; }
	class TSubclassOf<UUserWidget> GetBattleHUDClass() const { return BattleHUDClass; }
	//Maybe an own battle move
	//Maybe an own Shop menu
	//Maybe own Inventory menu

	//A function to show a specific menu witch takes a subclass	of userWidget and bool to check if in Game or UI. 
	bool ShowSpesificMenu(class TSubclassOf<class UUserWidget> ClassToShow, bool InGameOnly, bool ShowMouse);

	//Hides other menus on screen
	UFUNCTION(BlueprintCallable, Category = "BaseHUD")
		void HideMenus();

protected:

	//Players HUD during game, show Health, Money, Stamina
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "BaseHUD")
		class TSubclassOf<UUserWidget> GameplayHUDClass;

	//The death menu for when the player is dead
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "BaseHUD")
		class TSubclassOf<UUserWidget> DeadClass;

	//The pause menu for when the player uses pause. In game, and menu
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "BaseHUD")
		class TSubclassOf<UUserWidget> PauseClass;

	//The interface for when the player is in Battle, showing health, stamina, different moves, enemy health
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "BaseHUD")
		class TSubclassOf<UUserWidget> BattleHUDClass;

//protected:
//
//	//Players HUD during game, show Health, Money, Stamina
//	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "BaseHUD")
//		class TSubclassOf<UUserWidget> GameplayHUDClass;
//
//	//The death menu for when the player is dead
//	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "BaseHUD")
//		class TSubclassOf<UUserWidget> DeadClass;
//
//	//The pause menu for when the player uses pause. In game, and menu
//	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "BaseHUD")
//		class TSubclassOf<UUserWidget> PauseClass;
//
//	//The interface for when the player is in Battle, showing health, stamina, different moves, enemy health
//	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "BaseHUD")
//		class TSubclassOf<UUserWidget> BattleHUDClass;
};
