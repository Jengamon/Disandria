#include "StatesManager.h"

StateBase* StatesManager::currentState = NULL;

void StatesManager::checkCurrentState(RenderWindow* win)
{
    StateBase* state = StateManager::getCurrentState();
    if(StateMachine::getName(state) != StateMachine::getName(currentState)) {
        StateMachine::cleanupState(currentState, win);
        StateMachine::initState(state, win);
        currentState = state;
    } else {
        delete state;
    }
}

void StatesManager::renderCurrentState(RenderWindow* window)
{
    StateMachine::renderState(currentState, window);
}
