#include "ScriptAPILibrary.h"
#include "lib/GameManager.h"
#include <Poco/Foundation.h>
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

void ScriptAPILibrary::runScript(std::string scriptName)
{
    if(scriptAPI->scriptRequests() & SubmitType_FILENAME) {
        scriptAPI->scriptByFilename(scriptName);
    } else {
        std::ifstream in(GameManager::getGameFolderName() + scriptName + "." + scriptAPI->extension());
        if(scriptAPI->scriptRequests() & SubmitType_FILE) {
            scriptAPI->scriptByFile(in);
        } else {
            std::string contents;
            std::string line;
            while(getline(in, line)) {
                contents += line;
            }
            scriptAPI->scriptByString(contents);
        }
        in.close();
    }
}

void ScriptAPILibrary::initialize()
{
    poco_assert(scriptAPI != NULL);

    scriptAPI->initialize();
    scriptAPI->createBindings();
}

void ScriptAPILibrary::cleanup()
{
    scriptAPI->destroyBindings();
    scriptAPI->uninitialize();
}
