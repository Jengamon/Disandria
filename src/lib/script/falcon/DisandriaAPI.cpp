#include "DisandriaAPI.h"
#include "../ScriptAPI.h"

void DisandriaAPI::registerConstants(Falcon::Module* module)
{
	module->addConstant("DAPI_VERSION", 0.1);
}

void DisandriaAPI::registerFunctions(Falcon::Module* module)
{
}

void DisandriaAPI::registerClasses(Falcon::Module* module)
{
}

void DisandriaAPI::registerSingletons(Falcon::Module* module)
{
}
