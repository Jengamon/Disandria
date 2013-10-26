#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "StateBase.h"

class StateBase;

class StateMachine
{
public:
    static std::string getName(StateBase*);
    static bool initState(StateBase*, RenderWindow*);
    static void renderState(StateBase*, RenderWindow*);
    static void cleanupState(StateBase*, RenderWindow*);
};

#endif // STATEMACHINE_H
