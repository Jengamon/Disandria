#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <Thor/Graphics.hpp>
#include <Thor/Resources.hpp>
#include "Tileset.h"
#include "MapTile.h"
#include "../pugitmx/Parser.h"
#include "../helplib/stringh.h"

class Map
{
public:
    Map(std::string);
    Map();
    ~Map();
    std::string returnMapPath();
    std::string returnMapPathWithMap();
    std::string returnMapName();
    pugitmx::Map* returnMap() const;
    sf::Image* renderMap();
    sf::Shader* getShader();
    void createMap();
    void setShader(sf::Shader*);
    void clearShader();
private:
    pugitmx::Map* imap;
    std::string imapName;
    std::list<disandria::Tileset*> tilesets;
    thor::ResourceCache<sf::Image> imageLoader;
    sf::Image mapPicture;
    std::map<int, MapTile*> tiles;
    sf::Shader* mapShader;
    bool change;
    sf::Image* createTileLayer(pugitmx::TileLayer&);
    void clearTileLayer();
    sf::Image* renderTiles();
    disandria::Tileset* findTileTileset(pugitmx::Tile&);
    sf::Vector2i findTilesetTileLocation(pugitmx::Tile&, disandria::Tileset&);
};

#endif // MAP_H
