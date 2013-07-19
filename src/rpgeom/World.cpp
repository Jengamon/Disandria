#include "World.h"
using namespace rpgeom;

std::string World::getName()
{
	return name;
}

void World::addTile(std::string nm, Point pt, Tile tl)
{
	tl.setName(nm);
	tl.setLocation(pt);
	tiles.push_back(new Tile(tl));
}
	
Tile* World::getTile(std::string nm)
{
	for(std::list<Tile*>::iterator iter = tiles.begin(); iter != tiles.end(); iter++)
	{
		if((*iter)->getName() == nm)
			return *iter;
	}
	return NULL;
}
