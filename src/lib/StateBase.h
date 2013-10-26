#ifndef STATEBASE_H
#define STATEBASE_H

#include "RenderWindow.h"
#include "StateMachine.h"
#include <string>

class StateMachine;

class StateBase
{
    friend class StateMachine;
private:
    virtual std::string name() = 0;
    virtual bool onInit(RenderWindow*) = 0;
    virtual void onRender(RenderWindow*) = 0;
    virtual void onCleanup(RenderWindow*) = 0;
};

#endif // STATEBASE_H
