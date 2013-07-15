#include "StateManager.h"
#include "states/MainMenuState.h"

disandria::States::State StateManager::currentState;

StateBase* StateManager::getCurrentState()
{
	if(currentState == disandria::States::MAINMENU)
	{
		return new MainMenuState;
	}
	return NULL;
}

void StateManager::setCurrentState(disandria::States::State st)
{
	currentState = st;
}
