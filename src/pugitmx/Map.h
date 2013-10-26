#ifndef __MAP_H_
#define __MAP_H_

#include "../helplib/stringh.h"
#include <map>
#include <list>
#include "Tileset.h"
#include "TileLayer.h"
#include "ObjectGroup.h"

namespace pugitmx
{
class Map
{
public:
    Map(double vrs, std::string orient, unsigned int wd, unsigned int ht, unsigned int tlwd, unsigned int tlht, std::string bkclr = "#808080") : version(vrs), orientation(orient), width(wd), height(ht), tilewidth(tlwd), tileheight(tlht), backgroundcolor(bkclr) {};
    double getVersion() const;
    std::string getOrientation() const;
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    unsigned int getTileWidth() const;
    unsigned int getTileHeight() const;
    std::string getBackgroundColor() const;
    void registerProperty(std::string, std::string);
    std::string getProperty(std::string) const;
    void registerTileset(Tileset);
    std::list<Tileset> returnTilesets() const;
    std::list<Tileset>::iterator returnTilesetsIteratorB();
    std::list<Tileset>::iterator returnTilesetsIteratorE();
    void registerTileLayer(TileLayer);
    std::list<TileLayer> returnTileLayers() const;
    std::list<TileLayer>::iterator returnTileLayersIteratorB();
    std::list<TileLayer>::iterator returnTileLayersIteratorE();
    void registerObjectGroup(ObjectGroup);
    std::list<ObjectGroup> returnObjectGroups() const;
    std::list<ObjectGroup>::iterator returnObjectGroupsIteratorB();
    std::list<ObjectGroup>::iterator returnObjectGroupsIteratorE();
    virtual ~Map();
private:
    double version;
    std::string orientation;
    unsigned int width;
    unsigned int height;
    unsigned int tilewidth;
    unsigned int tileheight;
    std::string backgroundcolor;
    std::map<std::string, std::string> properties;
    std::list<Tileset> tilesets;
    std::list<TileLayer> tilelayers;
    std::list<ObjectGroup> objectgroups;
};
};

#endif // __MAP_H_
