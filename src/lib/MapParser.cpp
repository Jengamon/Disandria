#include "MapParser.h"
#include "GameManager.h"

pugitmx::Map* MapParser::currentMap;
std::string MapParser::mapname;

void MapParser::loadCurrentMap(std::string mapfile)
{
	currentMap = pugitmx::Parser::parseMap(GameManager::getGameFolderName() + "maps/" + mapfile + "/" + mapfile + ".tmx");
	mapname = mapfile;
}

pugitmx::Map* MapParser::getCurrentMap()
{
	return currentMap;
}

std::string MapParser::getMapName()
{
	return mapname;
}
