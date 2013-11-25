#include "MapLayer.h"

sf::Image* MapLayer::renderLayer()
{
    genImage();
    sf::Image* im = new sf::Image;
    im->create(xmlInfo.getWidth() * maptilewidth, xmlInfo.getHeight() * maptileheight);
    for(auto iter = tiles.begin(); iter != tiles.end(); iter++) {
        int renderPosInt = iter->first;
        MapTile* tileToRender = iter->second;
        sf::Vector2i renderPos(renderPosInt % width, renderPosInt / height);
        if(tileToRender->renderTile() != NULL) {
            im->copy(*tileToRender->renderTile(), renderPos.x * maptilewidth, renderPos.y * maptileheight);
        }
    }
    return im;
}

void MapLayer::genImage()
{
    int currentTile = 0;
    for(auto tliter = xmlInfo.grabTilesIteratorB(); tliter != xmlInfo.grabTilesIteratorE(); tliter++) {
        pugitmx::Tile* tile = &*tliter;
        disandria::Tileset* tileset = tlman->retrieveTilesetByGid(tile->getGid());
        sf::Vector2i loc;
        bool genLoc = false;
        if(tileset != NULL)
            loc = findTileLocationInTileset(tile->getGid(), *tileset);
        else
            genLoc = true;
        sf::Image* newMapTileImage = new sf::Image;
        if(genLoc) {
            tiles[currentTile++] = new MapTile(NULL, maptilewidth, maptileheight);
        } else {
            newMapTileImage->create(tileset->tilewidth, tileset->tileheight);
            newMapTileImage->copy(*tileset->img, 0, 0, sf::IntRect(loc.x * tileset->tilewidth, loc.y * tileset->tileheight, tileset->tilewidth, tileset->tileheight));
            tiles[currentTile++] = new MapTile(newMapTileImage, tileset->tilewidth, tileset->tileheight);
        }
        //TODO: Add actor rendering code here
        newMapTileImage = NULL;
    }
}

sf::Vector2i MapLayer::findTileLocationInTileset(unsigned int gid, disandria::Tileset& tileset)
{
    int picture_x = 0;
    int picture_y = 0;
    for(int il = 0; il < (gid - (tileset.firstgid)); il++) {
        picture_x++;
        if(picture_x >= (int(tileset.img->getSize().x) / tileset.tilewidth)) {
            picture_x = 0;
            picture_y++;
            if(picture_y >= (int(tileset.img->getSize().y) / tileset.tileheight)) {
                break;
            }
        }
    }
    return sf::Vector2i(picture_x, picture_y);
}

MapLayer::~MapLayer()
{
    for(auto iter = tiles.begin(); iter != tiles.end(); iter++) {
        if(iter->second != NULL) {
            delete iter->second;
        }
        tiles.erase(iter);
    }
}

