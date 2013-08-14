#ifndef SCRIPT_FALCON_DISANDRIAAPI_H
#define SCRIPT_FALCON_DISANDRIAAPI_H

#include <falcon/engine.h>

class DisandriaAPI
{
	public:
		static void registerConstants(Falcon::Module*);
		static void registerFunctions(Falcon::Module*);
		static void registerClasses(Falcon::Module*);
		static void registerSingletons(Falcon::Module*);
};

#endif // SCRIPT_FALCON_DISANDRIAAPI_H
