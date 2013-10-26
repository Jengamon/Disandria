#include "TileLayer.h"
#include "../helplib/Log.h"

using namespace pugitmx;

std::string TileLayer::getName() const
{
    return name;
}

int TileLayer::getWidth() const
{
    return width;
}

int TileLayer::getHeight() const
{
    return height;
}

void TileLayer::addTile(Tile tl)
{
    if(tiles.size() <= (width * height))
        tiles.push_back(tl);
}

std::list<Tile> TileLayer::grabTiles() const
{
    return tiles;
}

std::list<Tile>::iterator TileLayer::grabTilesIteratorB()
{
    return tiles.begin();
}

std::list<Tile>::iterator TileLayer::grabTilesIteratorE()
{
    return tiles.end();
}

Tile* TileLayer::findTile(int gd)
{
    for(std::list<Tile>::iterator iter = grabTilesIteratorB(); iter != grabTilesIteratorE(); iter++) {
        if(iter->getGid() == gd)
            return &*iter;
    }
    return NULL;
}

Tile* TileLayer::findTileByLocation(int reps)
{
    if(reps < 0 || reps > (width * height)) {
        return NULL;
    }

    std::list<Tile>::iterator iter = grabTilesIteratorB();
    for(int i = 0; i < reps; i++) {
        iter++;
    }

    return &*iter;
}

void TileLayer::registerProperty(std::string key, std::string value)
{
    properties[key] = value;
}

std::string TileLayer::getProperty(std::string key) const
{
    if(properties.find(key) == properties.end()) {
        return "";
    } else {
        return properties.find(key)->second;
    }
}
