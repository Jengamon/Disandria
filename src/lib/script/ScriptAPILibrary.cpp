#include "ScriptAPILibrary.h"
ScriptAPILibrary* ScriptAPILibrary::instance;

void ScriptAPILibrary::addAPI(std::string name, ScriptAPI* api)
{
    scriptLibrary[name] = api;
}

ScriptAPI* ScriptAPILibrary::getAPI(std::string apiName)
{
    for(auto iter = scriptLibrary.begin(); iter != scriptLibrary.end(); iter++) {
        if(iter->first == apiName) {
            return iter->second;
        }
    }
    return NULL;
}

void ScriptAPILibrary::clearAPI()
{
    for(auto iter = scriptLibrary.begin(); iter != scriptLibrary.end(); iter++) {
        delete iter->second;
    }
    scriptLibrary.erase(scriptLibrary.begin(), scriptLibrary.end());
}
