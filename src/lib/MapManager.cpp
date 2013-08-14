#include "MapManager.h"
#include "GameManager.h"
#include "../helplib/Log.h"

RenderWindow* MapManager::win = NULL;
Map* MapManager::cmap = NULL;

void MapManager::setRenderWindow(RenderWindow* _win)
{
	win = _win;
}

void MapManager::setMap(Map* _map)
{
	clearMap();
	cmap = _map;
}

void MapManager::clearMap()
{
	delete cmap;
	cmap = new Map;
}
		
void MapManager::renderMap()
{ 
	thor::BigSprite spr;
	thor::BigTexture tex;
	if(cmap != NULL)
	{
		sf::Image* mapImage = cmap->renderMap();
		if(mapImage != NULL)
		{
			tex.loadFromImage(*mapImage);
			tex.setSmooth(true);
			spr.setTexture(tex);
			spr.setOrigin(spr.getLocalBounds().width / 2, spr.getLocalBounds().height / 2);
			spr.setPosition(win->getSize().x / 2, win->getSize().y / 2);
			win->draw(spr);
		}
	}
}
