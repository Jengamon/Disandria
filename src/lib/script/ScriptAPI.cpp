#include "ScriptAPI.h"

void ScriptAPI::scriptByString(std::string) {}
void ScriptAPI::scriptByFilename(std::string) {}
void ScriptAPI::scriptByFile(std::ifstream&){}

void ScriptAPI::reset()
{
    destroyBindings();
    createBindings();
}
