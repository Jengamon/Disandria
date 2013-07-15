#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include <SFML/Graphics.hpp>
#include <Thor/Graphics.hpp>
#include <Thor/Resources.hpp>
#include "MapParser.h"
#include "RenderWindow.h"
#include "../helplib/stringh.h"

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

class MapManager
{
	public:
		static void setRenderWindow(RenderWindow*);
		static void bakeMap();
		static void renderMap();
	private:
		static sf::Image im;
		static pugitmx::Map* currentMap;
		static RenderWindow* win;
};

#endif // MAPMANAGER_H
	
