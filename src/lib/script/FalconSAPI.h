#ifndef __DISANDRIA_FALCONSAPI_H
#define __DISANDRIA_FALCONSAPI_H

#include <falcon/engine.h>
#include "ScriptAPI.h"

class FalconSAPI : public ScriptAPI
{
public:
    void initialize();
    void createBindings();
    int scriptRequests();
    void scriptByFilename(std::string);
    void destroyBindings();
    void uninitialize();
private:
    Falcon::VMachine* vm;
    Falcon::ModuleLoader* modloader;
};

#endif // __DISANDRIA_FALCONSAPI_H
