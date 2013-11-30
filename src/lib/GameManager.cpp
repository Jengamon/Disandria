#include "GameManager.h"
#include <Poco/Path.h>

std::string GameManager::gameName = "";
RenderWindow* GameManager::window = NULL;

void GameManager::setGameName(std::string gn)
{
    gameName = Poco::Path(gn).absolute().toString();
}

std::string GameManager::getGameFolderName()
{
    if(gameName != "")
        return gameName + "/";
    else
        return "";
}

void GameManager::setRenderWindow(RenderWindow* win)
{
    window = win;
}

RenderWindow* GameManager::getRenderWindow()
{
    return window;
}

double GameManager::getEngineVersion()
{
    return 0.2;
}
