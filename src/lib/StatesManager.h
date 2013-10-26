#ifndef STATESMANAGER_H
#define STATESMANAGER_H

#include "StateManager.h"
#include "StateMachine.h"

class StatesManager
{
public:
    static void checkCurrentState(RenderWindow*);
    static void renderCurrentState(RenderWindow*);
private:
    static StateBase* currentState;
};

#endif // STATESMANAGER_H
