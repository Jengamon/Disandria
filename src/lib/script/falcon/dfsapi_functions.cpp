#include "dfsapi_functions.h"
#include <cstdlib>

FALCON_FUNC closeSystem(Falcon::VMachine* vm)
{
	Falcon::Item* exitCode = vm->param(0);
	if(exitCode == NULL || !exitCode->isInteger())
	{
		exit(0);
	}
	exit(exitCode->forceInteger());
}