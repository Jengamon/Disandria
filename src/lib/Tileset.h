#ifndef TILESET_H
#define TILESET_H

#include <SFML/Graphics.hpp>

namespace disandria
{
	struct Tileset
	{
		unsigned int firstgid;
		unsigned int tilewidth;
		unsigned int tileheight;
		std::shared_ptr<sf::Image> img;
	};
};

#endif // TILESET_H
