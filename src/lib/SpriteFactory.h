#ifndef SPRITEFACTORY_H
#define SPRITEFACTORY_H

#include <SFML/Graphics.hpp>
#include <string>

class SpriteFactory
{
public:
    static sf::Texture* createTexture(std::string);
    static sf::Sprite createSprite(sf::Texture*);
};

#endif // SPRITEFACROY_H
