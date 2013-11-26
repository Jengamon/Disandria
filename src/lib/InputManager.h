#ifndef DISANDRIA_INPUTMANAGER_H
#define DISANDRIA_INPUTMANAGER_H

#include <Thor/Input.hpp>
#include <functional>
#include "../helplib/stringh.h"

namespace thor
{
using ActionCallback = std::function<void(thor::ActionContext<std::string>)>;
}

class InputManager
{
public:
    void addActionCallback(std::string evtnm, thor::Action act, thor::ActionCallback func);
    void removeActionCallback(std::string id);
    void removeAllActionCallbacks();
    void setupMap();
    thor::ActionMap<std::string>* getActionMap();
    thor::ActionMap<std::string>::CallbackSystem* getCallbackSystem();
private:
    thor::ActionMap<std::string> actionMap;
    thor::ActionMap<std::string>::CallbackSystem callbackSystem;
};

#endif // DISANDRIA_INPUTMANAGER_H
