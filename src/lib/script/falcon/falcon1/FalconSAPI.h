#ifndef __DISANDRIA_FALCONSAPI_H
#define __DISANDRIA_FALCONSAPI_H

#include <falcon/falcon.h>
#include <falcon/autocstring.h>
#include "lib/script/ScriptAPI.h"

class FalconSAPI : public ScriptAPI
{
public:
    void initialize();
    void createBindings();
    int scriptRequests();
    void scriptByFilename(std::string);
    void destroyBindings();
    void uninitialize();
    void reset();
    Falcon::VMachine* getVM() {
        return vm;
    }
private:
    Falcon::VMachine* vm;
    Falcon::Process* proc;
    Falcon::ModLoader* modloader;
};

#endif // __DISANDRIA_FALCONSAPI_H
