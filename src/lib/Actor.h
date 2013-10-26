#ifndef ACTOR_H
#define ACTOR_H

#include <SFML/Graphics.hpp>
#include "Square.h"

class Actor
{
public:
    Actor(disandria::Square*, sf::Vector2f);
private:
    disandria::Square* squ;
};

#endif // ACTOR_H
