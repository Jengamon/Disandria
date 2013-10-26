#ifndef __PARSER_H_
#define __PARSER_H_

#include "Map.h"
#include "../helplib/stringh.h"
#include "../pugixml/pugixml.hpp"

namespace pugitmx
{
class Parser
{
public:
    static Map* parseMap(std::string);
private:
    static Tileset* parseTileset(pugi::xml_node);
    static Image* parseImage(pugi::xml_node);
    static TileLayer* parseTileLayer(pugi::xml_node);
    static Tile* parseTile(pugi::xml_node);
    static Object* parseObject(pugi::xml_node);
    static ObjectGroup* parseObjectGroup(pugi::xml_node);
    static Polygon* parsePolygon(pugi::xml_node);
};
};

#endif // __PARSER_H_
