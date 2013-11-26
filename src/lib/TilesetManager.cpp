#include "TilesetManager.h"
#include <cassert>

void TilesetManager::addTileset(std::string name, unsigned int firstgid, unsigned int tlwidth, unsigned int tlheight, std::string loc, handleImage hndlim)
{
    disandria::Tileset* tlst = new disandria::Tileset;
    tlst->firstgid = firstgid;
    tlst->tilewidth = tlwidth;
    tlst->tileheight = tlheight;
    tlst->img = imageLoader.acquire(thor::Resources::fromFile<sf::Image>(loc));
    if(hndlim) {
        hndlim(tlst->img.get());
    }
    tilesets[name] = tlst;
}

disandria::Tileset* TilesetManager::retrieveTilesetByName(std::string name)
{
    auto tlst = tilesets.find(name);
    if(tlst != tilesets.end()) {
        assert(tlst->second != NULL);
        return tlst->second;
    }
    return NULL;
}

disandria::Tileset* TilesetManager::retrieveTilesetByGid(unsigned int gid)
{
    disandria::Tileset* tileset = NULL;
    for(auto tlsts = tilesets.begin(); tlsts != tilesets.end(); tlsts++) {
        assert(tlsts->second != NULL);
        if(tlsts->second->firstgid > gid || (tileset != NULL && tlsts->second->firstgid < tileset->firstgid)) {
            continue;
        }
        tileset = tlsts->second;
    }
    return tileset;
}

void clearTilesets()
{

}
