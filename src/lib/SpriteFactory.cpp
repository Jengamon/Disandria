#include "SpriteFactory.h"
#include "../helplib/Log.h"

sf::Texture* SpriteFactory::createTexture(std::string str)
{
    sf::Texture* tex = new sf::Texture;
    if(!tex->loadFromFile(str.c_str())) {
        Log::log("Failed to load " + str);
    }
    return tex;
}

sf::Sprite SpriteFactory::createSprite(sf::Texture* tex)
{
    sf::Sprite spr;
    spr.setTexture(*tex);
    return spr;
}
