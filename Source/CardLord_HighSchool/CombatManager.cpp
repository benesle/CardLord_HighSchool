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

		//Set the target to the character that is first in the turn order 
		this->tickTargetIndex = 0;
		this->SelectNextCharacter();
		break;

	case CombatState::CSTATE_Win:

		break;

	case CombatState::CSTATE_GameOver:
		break;
	}
}

//Select the next character in combat turn order
void CombatManager::SelectNextCharacter()
{
	this->waintingForCharacter = false;
	//Go through the turn order list if character is not available(dead?) or taken their choice 
	for (int i = this->tickTargetIndex; i < this->combatTurn.Num(); i++)
	{
		UGameCharacter* character = this->combatTurn[i];

		//Check if the HP is more then 0 to find a valid target
		if (character->HP > 0)
		{
			this->tickTargetIndex = i + 1;
			this->currentTickTarget = character;
			return;
		}
	}
	//sets ticktargetindex to -1 meaning and ticktarget to 0 no remaining characters in combat turn
	this->tickTargetIndex = -1;
	this->currentTickTarget = nullptr;
}

//This is where Tick should rather be and this controlls the states of the game 
bool CombatManager::UpdateState(float DeltaSeconds)
{
	switch (gameState)
	{
		//Decision state
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

		//If the decision is made go to the Make decision 
		//and check if there are any available targets
		if (decisionMade)
		{
			SelectNextCharacter();

			//If there is no next character then switch state to the action state
			if (this->tickTargetIndex == -1)
			{
				UE_LOG(LogTemp, Warning, TEXT("ChangeState"));
				this->SetState(CombatState::CSTATE_Action);
			}
		}
	}
	break;

	//The Action state
	case CombatState::CSTATE_Action:
	{
		//Ask character to execute their decision
		if (!this->waintingForCharacter)
		{
			this->currentTickTarget->BeginAction();
			this->waintingForCharacter = true;
		}
		
		bool actionDone = this->currentTickTarget->DoAction(DeltaSeconds);
		//Check if action is done 
		if (actionDone)
		{
			SelectNextCharacter();

			//If there is no next character then switch back to decision state
			if (this->tickTargetIndex == -1)
			{
				this->SetState(CombatState::CSTATE_Decision);
			}
		}
	}
	break;

	//break;

	//If character die or win return true
	//The combat is then finnished

	//Check if the state is GameOver 
	case CombatState::CSTATE_GameOver:
		return true;
		break;

		//Check if the state is win
	case CombatState::CSTATE_Win:
		return true;
		break;
	}

	//Check if any of the Characters have died
	//Check if it is GameOver for the player
	int deathCount = 0;

	for (int i = 0; i < this->playerGroup.Num(); i++)
	{
		if (this->playerGroup[i]->HP <= 0) deathCount++;
		
	}

	//If all of the players have died(There is no player left alive with HP over 0), switch to the gameOverState
	//If deathcount is the same as the number of players on the team
	if (deathCount == this->playerGroup.Num())
	{
		this->SetState(CombatState::CSTATE_GameOver);
		return false;
	}

	//Important values to acount for and will later be added to the player after the battle is finnished
	//Gold and XP will be added to the players Stats and information
	deathCount = 0;
	int32 Gold = 0;
	int32 XP = 0;

	//Check if the player have won
	for (int i = 0; i < this->enemyGroup.Num(); i++)
	{
		//Check if enemies have HP = 0 or less, but less then 0 will not be impossible
		if (this->enemyGroup[i]->HP <= 0)
		{
			//Set the HP of the enemy to 0
			//Add death to deathcount
			//Add gold and XP according to the enemies currently in the party to Gold and XP
			this->enemyGroup[i]->HP = 0;
			deathCount++;
			Gold += this->enemyGroup[i]->Gold;
			XP += this->enemyGroup[i]->XP;
		}
		
	}

	//If all of the enemies have died, switch to Win state
	//All the enemies in the group have died 
	if (deathCount == this->enemyGroup.Num())
	{
		//Switch state to the winning state
		//Add the gold and XP to the player
		this->SetState(CombatState::CSTATE_Win);
		TotalGold = Gold;
		XPTotal = XP;
		return false;
	}

	//Combat not finnished and returns false
	return false;
}

//The constructor for the combatManager
CombatManager::CombatManager(TArray<UGameCharacter*> playerGroup, TArray<UGameCharacter*> enemyGroup)
{
	this->playerGroup = playerGroup;
	this->enemyGroup = enemyGroup;

	//Add and set up combat turn for all the players
	for (int i = 0; i < playerGroup.Num(); i++)
	{
		this->combatTurn.Add(playerGroup[i]);
	}

	//Add and set up combat order for all the enemis
	for (int i = 0; i < enemyGroup.Num(); i++)
	{
		this->combatTurn.Add(enemyGroup[i]);
	}

	//The Decision State
	this->tickTargetIndex = 0;
	this->SetState(CombatState::CSTATE_Decision);

	for (int i = 0; i < this->combatTurn.Num(); i++)
	{
		this->combatTurn[i]->combatInstance = this;
	}

	this->tickTargetIndex = 0;
	this->SetState(CombatState::CSTATE_Decision);
}

//The combatManager deconstructor 
CombatManager::~CombatManager()
{
	//Set all the enemies to nullptr and remove them from the turn order
	for (int i = 0; i < this->enemyGroup.Num(); i++)
	{
		this->enemyGroup[i] = nullptr;
	}

	for (int i = 0; i < this->combatTurn.Num(); i++)
	{
		this->combatTurn[i]->combatInstance = nullptr;
	}
}
