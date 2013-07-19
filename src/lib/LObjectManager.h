#ifndef LOBJECTMANAGER_H
#define LOBJECTMANAGER_H

#include "MapParser.h"
#include "../rpgeom/World.h"

class LObjectManager
{
	public:
		static void update();
	private:
		static rpgeom::World* objects;
};

#endif // LOBJECTMANAGER_H
