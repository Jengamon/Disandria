#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include "RenderWindow.h"
#include "Map.h"

class MapManager
{
	public:
		static void setRenderWindow(RenderWindow*);
		static void setMap(Map*);
		static void clearMap();
		static void renderMap();
	private:
		static RenderWindow* win;
		static Map* cmap;
};

#endif // MAPMANAGER_H
	
