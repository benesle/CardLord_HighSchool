// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatManager.h"
#include "GameCharacter.h"

bool CombatManager::Tick(float DeltaSeconds)
{
	//Change Tick to this one
	return UpdateState(DeltaSeconds);

}

void CombatManager::SetState(CombatState gameState)
{
	this->gameState = gameState;

	switch (gameState)
	{
	case CombatState::CSTATE_Action:
	case CombatState::CSTATE_Decision:

		//Set the target to the character that is first in the combat order 
		this->tickTargetIndex = 0;
		this->SelectNextCharacter();
		break;

	case CombatState::CSTATE_Win:
		//Handle Win
		break;

	case CombatState::CSTATE_GameOver:
		//Handle GameOver
		break;
	}
}
//Select the nect character in combat turn order
void CombatManager::SelectNextCharacter()
{
	this->waintingForCharacter = false;
	for (int i = this->tickTargetIndex; i < this->combatTurn.Num(); i++)
	{
		UGameCharacter* character = this->combatTurn[i];

		if (character->HP > 0)
		{
			this->tickTargetIndex = i + 1;
			this->currentTickTarget = character;
			return;
		}
	}
	this->tickTargetIndex = -1;
	this->currentTickTarget = nullptr;
}

//This is where Tick should rather be
bool CombatManager::UpdateState(float DeltaSeconds)
{
	switch (gameState)
	{
	case CombatState::CSTATE_Decision:
	{
		//Ask character to make a decision
		if (!this->waintingForCharacter)
		{
			this->currentTickTarget->BeginDecision();
			this->waintingForCharacter = true;
		}

		//Ask if decision is made
		bool decisionMade = this->currentTickTarget->Makedecision(DeltaSeconds);

		if (decisionMade)
		{
			SelectNextCharacter();

			//If no next character then switch state
			if (this->tickTargetIndex == -1)
			{
				UE_LOG(LogTemp, Warning, TEXT("ChangeState"));
				this->SetState(CombatState::CSTATE_Action);
			}
		}
	}
	break;

	case CombatState::CSTATE_Action:
	{
		//Ask character to execute their decision
		if (!this->waintingForCharacter)
		{
			this->currentTickTarget->BeginAction();
			this->waintingForCharacter = true;
		}
		//When action is executed
		bool actionDone = this->currentTickTarget->DoAction(DeltaSeconds);

		if (actionDone)
		{
			SelectNextCharacter();

			//If no next character then switch back to decision state
			if (this->tickTargetIndex == -1)
			{
				this->SetState(CombatState::CSTATE_Decision);
			}
		}
	}
	break;

	//If character die or win return true
	case CombatState::CSTATE_GameOver:
		return true;
		break;
	case CombatState::CSTATE_Win:
		return true;
		break;
	}
	//Check if any of the Characters have died
	int deathCount = 0;

	for (int i = 0; i < this->playerGroup.Num(); i++)
	{
		if (this->playerGroup[i]->HP <= 0) deathCount++;
		
	}

	//If all of the players have died, switch to gameOverState
	if (deathCount == this->playerGroup.Num())
	{
		this->SetState(CombatState::CSTATE_GameOver);
		return false;
	}

	//Check if player win
	deathCount = 0;
	int32 Gold = 0;
	int32 XP = 0;

	for (int i = 0; i < this->enemyGroup.Num(); i++)
	{
		if (this->enemyGroup[i]->HP <= 0)
		{
			this->enemyGroup[i]->HP = 0;
			deathCount++;
			Gold += this->enemyGroup[i]->Gold;
			XP += this->enemyGroup[i]->XP;
		}
		
	}

	//If all enemis have died, switch to victory state
	if (deathCount == this->enemyGroup.Num())
	{
		this->SetState(CombatState::CSTATE_Win);
		TotalGold = Gold;
		XPTotal = XP;
		return false;
	}

	//Combat not finnished and returns false
	return false;
}

CombatManager::CombatManager(TArray<UGameCharacter*> playerGroup, TArray<UGameCharacter*> enemyGroup)
{
	this->playerGroup = playerGroup;
	this->enemyGroup = enemyGroup;

	//Set up combat order for all the players
	for (int i = 0; i < playerGroup.Num(); i++)
	{
		this->combatTurn.Add(playerGroup[i]);
	}

	//Set up combat order for all the enemis
	for (int i = 0; i < enemyGroup.Num(); i++)
	{
		this->combatTurn.Add(enemyGroup[i]);
	}

	this->tickTargetIndex = 0;
	this->SetState(CombatState::CSTATE_Decision);

	for (int i = 0; i < this->combatTurn.Num(); i++)
	{
		this->combatTurn[i]->combatInstance = this;
	}

	this->tickTargetIndex = 0;
	this->SetState(CombatState::CSTATE_Decision);
}

CombatManager::~CombatManager()
{
	//Enemis
	for (int i = 0; i < this->enemyGroup.Num(); i++)
	{
		this->enemyGroup[i] = nullptr;
	}

	for (int i = 0; i < this->combatTurn.Num(); i++)
	{
		this->combatTurn[i]->combatInstance = nullptr;
	}
}
