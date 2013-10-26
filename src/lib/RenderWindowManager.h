#ifndef RENDERWINDOWMANAGER_H
#define RENDERWINDOWMANAGER_H

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
