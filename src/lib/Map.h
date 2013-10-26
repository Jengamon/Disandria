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
    void setShader(sf::Shader*);
    void clearShader();
private:
    sf::Image* renderTiles();
    pugitmx::Map* imap;
    std::string imapName;
    std::list<disandria::Tileset*> tilesets;
    thor::ResourceCache<sf::Image> imageLoader;
    sf::Image mapPicture;
    std::map<int, MapTile*> tiles;
    sf::Shader* mapShader;
    bool change;
};

#endif // MAP_H
