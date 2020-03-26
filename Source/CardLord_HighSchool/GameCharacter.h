// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FCharacterData.h"
#include "FCharacterClassData.h"
#include "FEnemyData.h"
#include "ICombatAction.h"
#include "IDecisionMaker.h"
#include "GameCharacter.generated.h"

class CombatManager;
class ICombatAction;
class IDecisionMaker;

UCLASS(BlueprintType)

class CARDLORD_HIGHSCHOOL_API UGameCharacter : public UObject
{
    GENERATED_BODY()

public:

	IDecisionMaker* decisionMaker;
	ICombatAction* combatAction;
    FCharacterClassData* ClassData;
	CombatManager* combatInstance;
	

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterData)
        FString CharacterName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterData)
        int32 Health;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterData)
        int32 Stamina;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterData)
        int32 HP;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterData)
        int32 MP;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterData)
        int32 ATK;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterData)
        int32 DEF;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterData)
        int32 Crit;

public:
    
    static UGameCharacter* CreateGameCharacter(FCharacterData* characterData, UObject* outer);
    static UGameCharacter* CreateGameCharacter(FEnemyData* enemyData, UObject* outer);

	UGameCharacter* SelectTarget();

public:
    void BeginDestroy() override;

protected:
    float delayTimerTest;

public:

    void BeginDecision();
    bool Makedecision(float DeltaSeconds);

    void BeginAction();
    bool DoAction(float DeltaSeconds);

	bool isPlayer;
};