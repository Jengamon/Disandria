#include "Map.h"

using namespace pugitmx;

double Map::getVersion() const
{
	return version;
}

std::string Map::getOrientation() const
{
	return orientation;
}

unsigned int Map::getWidth() const
{
	return width;
}

unsigned int Map::getHeight() const
{
	return height;
}

unsigned int Map::getTileWidth() const
{
	return tilewidth;
}

unsigned int Map::getTileHeight() const
{
	return tileheight;
}

std::string Map::getBackgroundColor() const
{
	return backgroundcolor;
}

void Map::registerProperty(std::string key, std::string value)
{
	properties[key] = value;
}

std::string Map::getProperty(std::string key) const
{
	if(properties.find(key) == properties.end())
	{
		return "";
	}
	else
	{
		return properties.find(key)->second;
	}
}

void Map::registerTileset(Tileset tst)
{
	tilesets.push_back(tst);
}

std::list<Tileset> Map::returnTilesets() const
{
	return tilesets;
}

std::list<Tileset>::iterator Map::returnTilesetsIteratorB()
{
	return tilesets.begin();
}

std::list<Tileset>::iterator Map::returnTilesetsIteratorE()
{
	return tilesets.end();
}

void Map::registerTileLayer(TileLayer tl)
{
	tilelayers.push_back(tl);
}

std::list<TileLayer> Map::returnTileLayers() const
{
	return tilelayers;
}

std::list<TileLayer>::iterator Map::returnTileLayersIteratorB()
{
	return tilelayers.begin();
}

std::list<TileLayer>::iterator Map::returnTileLayersIteratorE()
{
	return tilelayers.end();
}

void Map::registerObjectGroup(ObjectGroup objgrp)
{
	objectgroups.push_back(objgrp);
}

std::list<ObjectGroup> Map::returnObjectGroups() const
{
	return objectgroups;
}

std::list<ObjectGroup>::iterator Map::returnObjectGroupsIteratorB()
{
	return objectgroups.begin();
}

std::list<ObjectGroup>::iterator Map::returnObjectGroupsIteratorE()
{
	return objectgroups.end();
}

Map::~Map()
{
	tilesets.erase(tilesets.begin(), tilesets.end());
	tilelayers.erase(tilelayers.begin(), tilelayers.end());
	objectgroups.erase(objectgroups.begin(), objectgroups.end());
}

