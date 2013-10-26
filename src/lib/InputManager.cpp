#include "InputManager.h"

void InputManager::setupMap()
{
    actionMap["QUIT"] = thor::Action(sf::Event::Closed) || thor::Action(sf::Keyboard::Escape, thor::Action::PressOnce);
}

void InputManager::addActionCallback(std::string evtnm, thor::Action act, thor::ActionCallback func)
{
    if(evtnm != "QUIT") {
        actionMap[evtnm] = act;
        callbackSystem.connect(evtnm, func);
    }
}

void InputManager::removeActionCallback(std::string id)
{
    if(id != "QUIT") {
        actionMap.removeAction(id);
        callbackSystem.clearConnections(id);
    }
}

void InputManager::removeAllActionCallbacks()
{
    actionMap.clearActions();
    callbackSystem.clearAllConnections();
    setupMap();
}

thor::ActionMap<std::string>* InputManager::getActionMap()
{
    return &actionMap;
}

thor::ActionMap<std::string>::CallbackSystem* InputManager::getCallbackSystem()
{
    return &callbackSystem;
}
