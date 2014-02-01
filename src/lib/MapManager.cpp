#include "MapManager.h"
#include "GameManager.h"
#include "../helplib/Log.h"
#include <Poco/Foundation.h>

RenderWindow* MapManager::win = NULL;
Map* MapManager::cmap = NULL;
sf::Image* MapManager::mapImage = NULL;
bool MapManager::changed = false;

void MapManager::setRenderWindow(RenderWindow* _win)
{
    win = _win;
}

void MapManager::setMap(Map* _map)
{
    clearMap();
    changed = true;
    cmap = _map;
}

void MapManager::clearMap()
{
    if(cmap != NULL)
        delete cmap;
    cmap = NULL;
}

void MapManager::renderMap()
{
    thor::BigSprite spr;
    thor::BigTexture tex;
    if(cmap != NULL) {
        if(changed) {
            mapImage = cmap->renderMap();
            changed = false;
        }
        poco_assert(mapImage != NULL);
        tex.loadFromImage(*mapImage);
        tex.setSmooth(true);
        spr.setTexture(tex);
        spr.setOrigin(spr.getLocalBounds().width / 2, spr.getLocalBounds().height / 2);
        spr.setPosition(win->getSize().x / 2, win->getSize().y / 2);
        poco_assert(win != NULL);
        win->draw(spr);
    }
}
