#include "ScriptAPI.h"

void ScriptAPI::reset()
{
	destroyBindings();
	createBindings();
}
