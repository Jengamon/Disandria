#include "FalconSAPI.h"
#include "lib/GameManager.h"
#include "DisandriaFalconSAPI.h"
#include "CEGUI/CEGUIFalconBinding.h"
#include <iostream>

void FalconSAPI::initialize()
{
    Falcon::Engine::Init();
    vm = new Falcon::VMachine();
    modloader = new Falcon::ModuleLoader(GameManager::getGameFolderName().c_str());
    modloader->addFalconPath();
    vm->link(Falcon::core_module_init());
    vm->link(DisandriaFalconSAPI::createBinding());
    vm->link(CEGUIFalconBinding::createBinding());
    vm->gcEnable(true);
}

void FalconSAPI::createBindings()
{
}

int FalconSAPI::scriptRequests()
{
    return SubmitType_FILENAME;
}

void FalconSAPI::scriptByFilename(std::string fileName)
{
    Falcon::Runtime rt(modloader, vm);
    try {
        rt.loadFile(fileName.c_str());
        vm->link(&rt);
        vm->launch();
    } catch(Falcon::Error* err) {
        Falcon::AutoCString edesc(err->toString());
        std::cerr << edesc.c_str() << std::endl;
        err->decref();
        return;
    }
    vm->unlink(&rt);
}

void FalconSAPI::destroyBindings()
{
}

void FalconSAPI::uninitialize()
{
    vm->unlink(Falcon::core_module_init());
    vm->unlink(DisandriaFalconSAPI::createBinding());
    vm->unlink(CEGUIFalconBinding::createBinding());
    delete modloader;
    vm->finalize();
    vm = NULL;
    Falcon::Engine::Shutdown();
}

void FalconSAPI::reset()
{
    vm->reset();
}
