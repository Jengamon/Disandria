#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "../helplib/stringh.h"
#include "RenderWindow.h"

class GameManager
{
public:
    static void setGameName(std::string);
    static std::string getGameFolderName();
    static void setRenderWindow(RenderWindow*);
    static RenderWindow* getRenderWindow();
    static double getEngineVersion();
private:
    static std::string gameName;
    static RenderWindow* window;
};

#endif // GAMEMANAGER_H
