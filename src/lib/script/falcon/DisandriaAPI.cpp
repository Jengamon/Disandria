#include "DisandriaAPI.h"
#include "../ScriptAPI.h"
#include "../../../helplib/Log.h"

#include "singletons/DisandriaSceneManager.h"

void DisandriaAPI::registerConstants(Falcon::Module* module)
{
    module->addConstant("DAPI_VERSION", 0.2);
}

void DisandriaAPI::registerFunctions(Falcon::Module* module)
{
}

void DisandriaAPI::registerClasses(Falcon::Module* module)
{
    Falcon::Symbol* sceneManagerSingleton = module->addSingleton("SceneManager");
    Falcon::Symbol* sceneManager = sceneManagerSingleton->getInstance();
    module->addClassMethod(sceneManager, "createScene", &DisandriaSceneManager::createScene);
    module->addClassMethod(sceneManager, "renderScene", &DisandriaSceneManager::renderScene);
    module->addClassMethod(sceneManager, "deleteScene", &DisandriaSceneManager::deleteScene);
}

void DisandriaAPI::registerSingletons(Falcon::Module* module)
{
}
