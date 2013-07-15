#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "StateBase.h"
#include "States.h"

class StateManager
{
	public:
		static StateBase* getCurrentState();
		static void setCurrentState(disandria::States::State);
	private:
		static disandria::States::State currentState;
};

#endif // STATEMANAGER_H
