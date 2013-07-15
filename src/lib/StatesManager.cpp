#include "StatesManager.h"

StateBase* StatesManager::currentState = NULL;

void StatesManager::checkCurrentState(RenderWindow* win)
{
	StateBase* state = StateManager::getCurrentState();
	if(StateMachine::getName(state) != StateMachine::getName(currentState))
	{
		StateMachine::cleanupState(currentState);
		StateMachine::initState(state, win);
		currentState = state;
	}
}

void StatesManager::renderCurrentState(RenderWindow* window)
{
	StateMachine::renderState(currentState, window);
}
