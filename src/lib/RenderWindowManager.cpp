#include "RenderWindowManager.h"

std::map<int, RenderWindow*> RenderWindowManager::renderWindows;
std::map<std::string, int> RenderWindowManager::stringToIntMap;

bool RenderWindowManager::registerRenderWindow(int id, Params params)
{
    if(id < 0)
        return false;
    std::map<int, RenderWindow*>::iterator key = renderWindows.find(id);
    if(key == renderWindows.end()) {
        renderWindows[id] = new RenderWindow(params.width, params.height, params.name);
        return true;
    }
    return false;
}

bool RenderWindowManager::linkRegisterToString(std::string sid, int id)
{
    if(id < 0)
        return false;
    std::map<std::string, int>::iterator key = stringToIntMap.find(sid);
    if(key == stringToIntMap.end()) {
        stringToIntMap[sid] = id;
        return true;
    }
    return false;
}

RenderWindow* RenderWindowManager::getRenderWindow(int id)
{
    std::map<int, RenderWindow*>::iterator key = renderWindows.find(id);
    if(key != renderWindows.end())
        return key->second;
    return NULL;
}

RenderWindow* RenderWindowManager::getRenderWindow(std::string sid)
{
    std::map<std::string, int>::iterator keysti = stringToIntMap.find(sid);
    if(keysti != stringToIntMap.end())
        return getRenderWindow(keysti->second);
    return NULL;
}

void RenderWindowManager::cleanupRenderWindow(int id)
{
    std::map<int, RenderWindow*>::iterator key = renderWindows.find(id);
    if(key != renderWindows.end()) {
        delete key->second;
        renderWindows.erase(key);
    }
}

void RenderWindowManager::cleanupRenderWindow(std::string sid)
{
    std::map<std::string, int>::iterator keysti = stringToIntMap.find(sid);
    if(keysti != stringToIntMap.end())
        return cleanupRenderWindow(keysti->second);
}

int RenderWindowManager::getStringToRegisterMapping(std::string sid)
{
    std::map<std::string, int>::iterator keysti = stringToIntMap.find(sid);
    if(keysti != stringToIntMap.end())
        return keysti->second;
    return -1;
}
