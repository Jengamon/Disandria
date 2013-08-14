#include "Actor.h"

Actor::Actor(disandria::Square* square, sf::Vector2f locvec)
{
	squ = new disandria::Square(*square);
}
