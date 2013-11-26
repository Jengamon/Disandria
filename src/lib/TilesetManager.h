#ifndef DISADNRIA_TILESETMANAGER_H
#define DISADNRIA_TILESETMANAGER_H

#include <map>
#include <string>
#include <functional>
#include <SFML/Graphics.hpp>
#include <Thor/Resources.hpp>
#include "Tileset.h"

using handleImage = std::function<void(sf::Image*)>;

class TilesetManager
{
public:
    TilesetManager() {
        imageLoader.setReleaseStrategy(thor::Resources::AutoRelease);
    }
    void addTileset(std::string, unsigned int, unsigned int, unsigned int, std::string, handleImage = NULL);
    disandria::Tileset* retrieveTilesetByName(std::string);
    disandria::Tileset* retrieveTilesetByGid(unsigned int);
    void clearTilesets();
private:
    std::map<std::string, disandria::Tileset*> tilesets;
    thor::ResourceCache<sf::Image> imageLoader;
};

#endif // DISADNRIA_TILESETMANAGER_H
