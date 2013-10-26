#include "StateManager.h"
#include "states/MainMenuState.h"
#include "states/MainGameState.h"

disandria::States::State StateManager::currentState;

StateBase* StateManager::getCurrentState()
{
    if(currentState == disandria::States::MAINMENU) {
        return new MainMenuState;
    } else if(currentState == disandria::States::MAINGAME) {
        return new MainGameState;
    }
    return NULL;
}

void StateManager::setCurrentState(disandria::States::State st)
{
    currentState = st;
}
