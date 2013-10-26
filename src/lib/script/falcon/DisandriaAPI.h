#ifndef SCRIPT_FALCON_DISANDRIAAPI_H
#define SCRIPT_FALCON_DISANDRIAAPI_H

#include <falcon/engine.h>

class DisandriaAPI
{
public:
    void registerConstants(Falcon::Module*);
    void registerFunctions(Falcon::Module*);
    void registerClasses(Falcon::Module*);
    void registerSingletons(Falcon::Module*);
};

#endif // SCRIPT_FALCON_DISANDRIAAPI_H
