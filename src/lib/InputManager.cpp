#include "InputManager.h"
#include <iostream>

void InputManager::setupMap()
{
    actionMap["QUIT"] = thor::Action(sf::Event::Closed) || thor::Action(sf::Keyboard::Escape, thor::Action::PressOnce);
}

void InputManager::addActionCallback(std::string evtnm, thor::Action act, thor::ActionCallback func)
{
    addAction(evtnm, act);
    addCallback(evtnm, func);
}

void InputManager::addAction(std::string evtnm, thor::Action act)
{
    actionMap[evtnm] = act;
}

void InputManager::addCallback(std::string evtnm, thor::ActionCallback func)
{
    std::cout << evtnm << std::endl;
    callbackSystem.connect(evtnm, func);
}

void InputManager::update(sf::Window& win)
{
    actionMap.update(win);
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
