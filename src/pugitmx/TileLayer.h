#ifndef __TILELAYER_H_
#define __TILELAYER_H_

#include "../helplib/stringh.h"
#include "Tile.h"
#include <list>
#include <map>

namespace pugitmx
{
class TileLayer
{
public:
    TileLayer() {};
    TileLayer(std::string nme, int wd, int ht) : name(nme), width(wd), height(ht) {};
    std::string getName() const;
    int getWidth() const;
    int getHeight() const;
    void addTile(Tile);
    std::list<Tile> grabTiles() const;
    std::list<Tile>::iterator grabTilesIteratorB();
    std::list<Tile>::iterator grabTilesIteratorE();
    Tile* findTile(int);
    Tile* findTileByLocation(int);
    void registerProperty(std::string, std::string);
    std::string getProperty(std::string) const;
private:
    std::string name;
    int width;
    int height;
    std::map<std::string, std::string> properties;
    std::list<Tile> tiles;
};
};

#endif // __TILELAYER_H_
