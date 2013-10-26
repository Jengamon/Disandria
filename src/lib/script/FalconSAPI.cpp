#include "FalconSAPI.h"
#include "falcon/DisandriaAPI.h"
#include "../GameManager.h"
#include "../../helplib/Log.h"

FalconSAPI::FalconSAPI()
{
    Falcon::Engine::Init();
    try {
        m_loader = new Falcon::ModuleLoader(("./" + GameManager::getGameFolderName()).c_str());
        m_loader->addFalconPath();
        addPath(".");
        runtime = NULL;
        vm = NULL;
    } catch(Falcon::Error* err) {
        Falcon::AutoCString edesc(err->toString());
        Log::log(edesc.c_str());
    }
}


void FalconSAPI::createRuntime()
{
    runtime = new Falcon::Runtime(m_loader);
}

void FalconSAPI::addPath(std::string pta)
{
    m_loader->addDirectoryBack(pta.c_str());
}

void FalconSAPI::quickInitialize(std::string script_name)
{
    createRuntime();
    loadFile(script_name);
    createVM();
    loadCoreModule();
    linkRuntime();
}

void FalconSAPI::loadCoreModule()
{
    try {
        if(vm != NULL)
            vm->link(Falcon::core_module_init());
    } catch(Falcon::Error* err) {
        Falcon::AutoCString edesc(err->toString());
        Log::log(edesc.c_str());
    }
}

void FalconSAPI::loadExternalModule(Falcon::Module* mod)
{
    try {
        if(vm != NULL)
            vm->link(mod);
    } catch(Falcon::Error* err) {
        Falcon::AutoCString edesc(err->toString());
        Log::log(edesc.c_str());
    }
}

void FalconSAPI::linkRuntime()
{
    try {
        if(vm != NULL && runtime != NULL)
            vm->link(runtime);
    } catch(Falcon::Error* err) {
        Falcon::AutoCString edesc(err->toString());
        Log::log(edesc.c_str());
    }
}

void FalconSAPI::launch(std::string fl)
{
    try {
        if(vm != NULL) {
            if(fl != "~")
                vm->launch(fl.c_str());
            else
                vm->launch();
        }
    } catch(Falcon::Error* err) {
        Falcon::AutoCString edesc(err->toString());
        Log::log(edesc.c_str());
    }
}

void FalconSAPI::loadFile(std::string flnm)
{
    try {
        if(runtime != NULL)
            runtime->loadFile(flnm.c_str());
    } catch(Falcon::Error* err) {
        Falcon::AutoCString edesc(err->toString());
        Log::log(edesc.c_str());
    }
}

void FalconSAPI::createVM()
{
    vm = new Falcon::VMachine();
}

FalconSAPI::~FalconSAPI()
{
    vm->finalize();
    delete runtime;
    delete m_loader;
    Falcon::Engine::Shutdown();
}

Falcon::Module* createAppModule()
{
    Falcon::Module* module = new Falcon::Module;
    module->name("DisandriaEngine");
    DisandriaAPI apiObject;
    apiObject.registerConstants(module);
    apiObject.registerFunctions(module);
    apiObject.registerClasses(module);
    apiObject.registerSingletons(module);
    return module;
}
