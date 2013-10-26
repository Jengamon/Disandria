#include "DisandriaSceneManager.h"

std::map<std::string, Scene*> DisandriaSceneManager::scenes;

void DisandriaSceneManager::createScene(Falcon::VMachine* vm)
{
    vm->retnil();
}

void DisandriaSceneManager::renderScene(Falcon::VMachine* vm)
{
    vm->retnil();
}

void DisandriaSceneManager::deleteScene(Falcon::VMachine* vm)
{
    vm->retnil();
}
