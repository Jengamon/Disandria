#ifndef RENDERWINDOWMANAGER_H
#define RENDERWINDOWMANAGER_H

/*
 * RenderWindowManager.h
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



#include <map>
#include "RenderWindow.h"

class RenderWindowManager
{
public:
    struct Params {
        int width;
        int height;
        std::string name;
        static Params createParam(int w, int h, std::string n) {
            Params self;
            self.width = w;
            self.height = h;
            self.name = n;
            return self;
        }
    };
    static bool registerRenderWindow(int, Params);
    static bool linkRegisterToString(std::string, int);
    static RenderWindow* getRenderWindow(int);
    static RenderWindow* getRenderWindow(std::string);
    static void cleanupRenderWindow(int);
    static void cleanupRenderWindow(std::string);
    static int getStringToRegisterMapping(std::string);
private:
    static std::map<int, RenderWindow*> renderWindows;
    static std::map<std::string, int> stringToIntMap;
};

#endif // RENDERWINDOWMANAGER_H
