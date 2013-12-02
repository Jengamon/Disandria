#include "ScriptAPI.h"

void ScriptAPI::scriptByString(std::string) {}
void ScriptAPI::scriptByFilename(std::string) {}
void ScriptAPI::scriptByFile(std::ifstream&) {}
std::string ScriptAPI::extension() { return ""; }

void ScriptAPI::reset()
{
    destroyBindings();
    createBindings();
}
