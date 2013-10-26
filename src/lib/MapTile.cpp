#include "MapTile.h"

MapTile::MapTile(sf::Image* baseImage, unsigned int _w, unsigned int _h) : actorOnTile(NULL), createdImage(NULL)
{
    tileImg = baseImage;
    width = _w;
    height = _h;
}

void MapTile::renderActor(Actor* actor)
{
    actorOnTile = actor;
}

sf::Image* MapTile::renderTile()
{
    if(createdImage != NULL) {
        delete createdImage;
        createdImage = NULL;
    }
    createdImage = new sf::Image;
    createdImage->create(width, height);
    createdImage->copy(*tileImg, 0, 0);
    if(actorOnTile != NULL) {
        //TODO: Insert actor rendering code here.
    }
    return createdImage;
}

MapTile::~MapTile()
{
    if(tileImg != NULL)
        //delete tileImg;
        if(createdImage != NULL)
            delete createdImage;
    tileImg = NULL;
    createdImage = NULL;
}
