#ifndef ACTOR_H
#define ACTOR_H

#include <SFML/Graphics.hpp>
#include "Square.h"

/**
 * @todo Complete this class, so that Character rendering can be started.
 */
class Actor
{
public:
    Actor(disandria::Square*, sf::Vector2f);
private:
    disandria::Square* squ;
};

#endif // ACTOR_H
