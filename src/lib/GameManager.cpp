#include "GameManager.h"

std::string GameManager::gameName = "";
RenderWindow* GameManager::window = NULL;

void GameManager::setGameName(std::string gn)
{
	gameName = gn;
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
