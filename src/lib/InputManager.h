#ifndef DISANDRIA_INPUTMANAGER_H
#define DISANDRIA_INPUTMANAGER_H

/*
 * InputManager.h
 * This file is part of Disandria
 *
 * Copyright (C) 2013 - Bob Hostern
 *
 * Disandria is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Disandria is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Disandria. If not, see <http://www.gnu.org/licenses/>.
 */



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
