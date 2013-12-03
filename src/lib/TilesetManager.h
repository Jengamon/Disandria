#ifndef DISADNRIA_TILESETMANAGER_H
#define DISADNRIA_TILESETMANAGER_H

#include <map>
#include <string>
#include <functional>
#include <SFML/Graphics.hpp>
#include <Thor/Resources.hpp>
#include "Tileset.h"

using handleImage = std::function<void(sf::Image*)>;

/**
 * @todo Make this class more of a manager, rather than a preloader.
 */
class TilesetManager
{
public:
	/**
	 * @brief Make a TilesetManager
	 * 
	 * Creates a TilesetManager. Nothing to it...
	 */
    TilesetManager() {
        imageLoader.setReleaseStrategy(thor::Resources::AutoRelease);
    }
    
    /**
     * @brief Add a tileset to loaded list
     * @todo Make this a request loader, rather than a storage function.
     * @param nm Name that can load this tileset with retrieveTilesetByName()
     * @param fgid First GID of tileset
     * @param tlwd Tile width of tileset
     * @param tlht Tile height of tileset
     * @param loc Image location
     * 
     * Adds a preloaded tileset to the TilesetManager
     */
    void addTileset(std::string nm, unsigned int fgid, unsigned int tlwd, unsigned int tlht, std::string loc, handleImage imFunc = NULL);
    
    /**
     * @brief Get a disandria::Tileset by name
     * @param nm Name of tileset to retrieve
     * 
     * Get a pointer to a disandria::Tileset by its registered name
     */
    disandria::Tileset* retrieveTilesetByName(std::string nm);
    
    /**
     * @brief Get a disandria::Tileset by GID
     * @param gid GID of tile to retrieve
     *
     * Get a pointer to a disandria::Tileset by a MapTile's GID
     */
    disandria::Tileset* retrieveTilesetByGid(unsigned int gid);
    
    /**
     * @todo Implement this!
     */
    void clearTilesets();
private:
    std::map<std::string, disandria::Tileset*> tilesets;
    thor::ResourceCache<sf::Image> imageLoader;
};

#endif // DISADNRIA_TILESETMANAGER_H
