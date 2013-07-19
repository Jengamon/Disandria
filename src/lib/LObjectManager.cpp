#include "LObjectManager.h"
#include "../helplib/Log.h"
#include "GameManager.h"

rpgeom::World* LObjectManager::objects = NULL;

void LObjectManager::update()
{
	pugitmx::Map* map = MapParser::getCurrentMap();
	pugitmx::ObjectGroup* lobjgrp = NULL;
	for(std::list<pugitmx::ObjectGroup>::iterator iter = map->returnObjectGroupsIteratorB(); iter != map->returnObjectGroupsIteratorE(); iter++)
	{
		if(iter->getName() == "LowerObjects" || iter->getName() == "LowerObject" || iter->getName() == "lower" || iter->getName() == "Lower Objects" || iter->getName() == "Lower Object")
			lobjgrp = &*iter;
	}
	if(lobjgrp == NULL)
		Log::log("Failed to find a LowerObject Object Group in " + GameManager::getGameFolderName() + "maps/" + MapParser::getMapName() + "/" + MapParser::getMapName() + ".tmx");
	
	if(lobjgrp->getWidth() > map->getWidth() || lobjgrp->getHeight() > map->getHeight())
		Log::log("INVALID MAP FILE: Object layer width and/or height is greater than map's.");

	for(std::list<pugitmx::Object>::iterator iter = lobjgrp->grabObjectsIteratorB(); iter != lobjgrp->grabObjectsIteratorE(); iter++)
	{
		if(iter->isEllipse())
			Log::log(PE::Logging::WARNING, "Engine does not currently support ellipses. Will treat as Square");
		if(iter->getPolygon().getPoints() != "")
			Log::log("Engine does not support polygons. Cannot transform Polygon into Square.");
		objects = new rpgeom::World("LObject", map->getWidth(), map->getHeight());
		// TODO: Add the object-to-rpgeom::Tile code
	}
}
