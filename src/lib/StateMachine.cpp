#include "StateMachine.h"

std::string StateMachine::getName(StateBase* state)
{
	if(state != NULL)
		return state->name();
	else
		return "";
}

bool StateMachine::initState(StateBase* state, RenderWindow* window)
{
	if(state != NULL)
		return state->onInit(window);
	else
		return true;
}

void StateMachine::renderState(StateBase* state, RenderWindow* window)
{
	if(state != NULL)
		state->onRender(window);
}

void StateMachine::cleanupState(StateBase* state)
{
	if(state != NULL)
	{
		state->onCleanup();
		delete state;
	}
}
