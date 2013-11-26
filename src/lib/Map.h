#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <Thor/Graphics.hpp>
#include <Thor/Resources.hpp>
#include "Tileset.h"
#include "MapTile.h"
#include "../pugitmx/Parser.h"
#include "../helplib/stringh.h"
#include "MapLayer.h"
#include "TilesetManager.h"

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
    void setShader(sf::Shader*);
    void clearShader();
private:
    pugitmx::Map* imap;
    std::string imapName;
    sf::Image mapPicture;
    sf::Shader* mapShader;
    TilesetManager tlstman;
    sf::Image* createTileLayer(pugitmx::TileLayer&);
};

#endif // MAP_H
