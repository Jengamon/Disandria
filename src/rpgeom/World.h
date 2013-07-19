#ifndef _RPGEOM_WORLD_H
#define _RPGEOM_WORLD_H

#include <string>
#include "Tile.h"
#include <list>

namespace rpgeom
{
	// TODO: Add the tile movement code! (It's not advised to move a rpgeom::Tile directly.)
	class World
	{
		public:
			World(std::string n, int rb, int bb) : name(n), rightBoundary(rb), bottomBoundary(bb) {}
			std::string getName();
			void addTile(std::string, Point, Tile);
			Tile* getTile(std::string);
		private:
			std::string name;
			int rightBoundary;
			int bottomBoundary;
			std::list<Tile*> tiles;
	};
};

#endif // _RPGEOM_WORLD_H
