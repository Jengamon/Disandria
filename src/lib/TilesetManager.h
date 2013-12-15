#ifndef DISADNRIA_TILESETMANAGER_H
#define DISADNRIA_TILESETMANAGER_H

/*
 * TilesetManager.h
 * This file is part of Disandria
 *
 * Copyright (C) 2013 - Bob Hostern
 *
 * Disandria is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Disandria is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Disandria. If not, see <http://www.gnu.org/licenses/>.
 */



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
