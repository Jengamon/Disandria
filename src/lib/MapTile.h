#ifndef DISANDRIA_MAPTILE_H
#define DISANDRIA_MAPTILE_H

#include "Actor.h"
#include <SFML/Graphics.hpp>

class MapTile
{
public:
    MapTile(sf::Image*, unsigned int, unsigned int);
    void renderActor(Actor*);
    sf::Image* renderTile();
    ~MapTile();
private:
    sf::Image* tileImg;
    Actor* actorOnTile;
    sf::Image* createdImage;
    unsigned int width;
    unsigned int height;
};

#endif // DISANDRIA_MAPTILE_H
