#ifndef MAP_H
#define MAP_H

/*
 * Map.h
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
    /**
     * @brief Initialize Map with a .tmx location
     * @param path Path to .tmx location
     *
     * Load a .tmx from this location. The location is actually a folder.
     * For example, if given "tx", will try to load GameManager#getGameFolderName() + "maps/tx/tx.tmx"
     */
    Map(std::string path);

    /**
     * @brief Make an empty Map
     * @note Map displays nothing, as that's what it is
     *
     * Initializes an empty map
     */
    Map();

    /**
     * @brief Map cleanup.
     *
     * Cleans up the map, so that it's space can be used for other things, such as more Maps.
     */
    ~Map();

    /**
     * @brief Get Map path
     *
     * Gets the loaded map's path, without including it.
     */
    std::string returnMapPath();

    /**
     * @brief Get Map path
     *
     * Gets the loaded map's path, including it.
     */
    std::string returnMapPathWithMap();

    /**
     * @brief Get Map name
     *
     * Gets the string with which the Map was loaded.
     */
    std::string returnMapName();

    /**
     * @brief Get loaded Map struture
     *
     * Gives the in-memory structure of Map, that was used in constructing the map.
     */
    pugitmx::Map* returnMap() const;

    /**
     * @brief Render map
     *
     * Renders map to an Image for rendering with a RenderWindow.
     */
    sf::Image* renderMap();

    /**
     * @deprecated in favor of a universal shader system
     * @brief Get Map shader
     *
     * Gets the map's shader
     */
    sf::Shader* getShader();

    /**
     * @deprecated in favor of a universal shader system
     * @brief Set Map shader
     * @param shd Shader pointer to set to shader
     *
     * Sets the map's shader
     */
    void setShader(sf::Shader* shd);

    /**
     * @deprecated in favor of a universal shader system
     * @brief Clear Map shader
     *
     * Clears the map's shader
     */
    void clearShader();
private:
    /**
     * @brief Map structure
     *
     * In-memory Map structure that is used to create and render the map.
     * Is loaded by the pugitmx library.
     */
    pugitmx::Map* imap;

    /**
     * @brief Map name
     *
     * Holds the maps name. That's really it...
     */
    std::string imapName;

    /**
     * @brief Map image
     *
     * Holds the map image that is sent to be rendered by a RenderWindow.
     */
    sf::Image mapPicture;

    /**
     * @deprecated in favor of a universal shader system
     * @brief Shader pointer to Map shader
     *
     * A pointer to the current Map shader
     */
    sf::Shader* mapShader;

    /**
     * @brief TilesetManager that loads all tilesets
     *
     * TilesetManager which loads all tilesets that are used by MapLayer, which
     * is how a Map internally generates it's image.
     */
    TilesetManager tlstman;

    /**
     * @brief Convert parsed data to reality
     * @todo Currently returns nothing, will change soon
     *
     * Converts parsed data in a pugitmx::TileLayer into a MapLayer, then
     * returns the image.
     */
    sf::Image* createTileLayer(pugitmx::TileLayer&);
};

#endif // MAP_H
