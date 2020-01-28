// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BattleGameModeBase.generated.h"

class AMyCharacterBaseBattle;
//enum to store the current state of gameplay
UENUM()
enum class EGamePlayState
{
	EPlaying,
	EBattle,
	EGameOver
	
};
/**
 * 
 */
UCLASS()
class CARDLORD_HIGHSCHOOL_API ABattleGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
		virtual void StartPlay() override;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	AMyCharacterBaseBattle* MyCharacter;

public: ABattleGameModeBase();

		/** Returns the current playing state */
		UFUNCTION(BlueprintPure, Category = "Health")
			EGamePlayState GetCurrentState() const;

		/** Sets a new playing state */
		void SetCurrentState(EGamePlayState NewState);

		UPROPERTY(EditAnywhere, Category = "Health")
			TSubclassOf<class UUserWidget> HUDWidgetClass;

		UPROPERTY(EditAnywhere, Category = "Health")
			class UUserWidget* CurrentWidget;

private:
	/**Keeps track of the current playing state */
	EGamePlayState CurrentState;

	/**Handle any function calls that rely upon changing the playing state of our game */
	void HandleNewState(EGamePlayState NewState);

};
