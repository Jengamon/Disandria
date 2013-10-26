#include "Tileset.h"

using namespace pugitmx;

unsigned int Tileset::getFirstGid() const
{
    return firstgid;
}

std::string Tileset::getName() const
{
    return name;
}

unsigned int Tileset::getTileWidth() const
{
    return tilewidth;
}

unsigned int Tileset::getTileHeight() const
{
    return tileheight;
}

Image Tileset::getImage() const
{
    return image;
}

void Tileset::registerProperty(TilePropertyKey key, std::string value)
{
    properties[String<int>::toString(key.id) + key.propertyname] = value;
}

std::string Tileset::getProperty(TilePropertyKey key) const
{
    std::string tkey = String<int>::toString(key.id) + key.propertyname;
    if(properties.find(tkey) != properties.end()) {
        return properties.find(tkey)->second;
    } else {
        return "";
    }
}
