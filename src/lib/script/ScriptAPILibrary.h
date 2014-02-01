#ifndef __DISANDRIA_SCRIPTAPILIBRARY_H
#define __DISANDRIA_SCRIPTAPILIBRARY_H

#include <map>
#include "ScriptAPI.h"

class ScriptAPILibrary
{
public:
    /* When you use this function, please hand over control of the API object
     * to the Library, as it currently would own it, and can delete it at it's own whim
     * and fancy.
     */
    void addAPI(std::string, ScriptAPI* api);
    /* Single API instance is shared, so keep the API clean, and always reverse changes that you
     * make, so that the API is exactly as you left it.
     *
     * Beware: Do NOT delete the API, as it is a shared instance. Delete it, and you have a dangling pointer.
     * Dangling pointers are bad, so don't delete an API object that is returned using this method.
     */
    ScriptAPI* getAPI(std::string);
    /* Why you hand over control.
     * This function deletes EVERY API it owns.
     * Pretty, huh?
     */
    void clearAPI();

    void runScript(std::string);
    void initialize();
    void cleanup();

    ScriptAPI* scriptAPI;
    static ScriptAPILibrary* instance;
private:
    std::map<std::string, ScriptAPI*> scriptLibrary;
};

#endif // __DISANDRIA_SCRIPTAPILIBRARY_H
