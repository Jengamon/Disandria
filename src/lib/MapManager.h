#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include "RenderWindow.h"
#include "Map.h"

/**
 * @note Uses an old format, will change this.
 * @todo Set up this in the new format
 */
class MapManager
{
public:

	/**
	 * @deprecated as this is to be replaced by a Scene-based API.
	 * @brief Sets the RenderWindow to draw to.
	 * 
	 * Sets the RenderWindow to render to. Required as this needs to know where to render to.
	 */
    static void setRenderWindow(RenderWindow* rw);
    
    /**
     * @brief Sets the Map to render
     * 
     * Sets the Map that this class renders as the current map. Should be a valid Map.
     */
    static void setMap(Map* mp);
    
    /**
     * @brief Cleanup current map
     * 
     * Deletes and cleans up the current map.
     */
    static void clearMap();
    
    /**
     * @deprecated as this will be replaced by a Scene-based
     * @brief Render Map to RenderWindow
     * 
     * ...Isn't it obvious?
     */
    static void renderMap();
private:
	/**
	 * @brief The RenderWindow that this class uses
	 * 
	 * ...Read the brief.
	 */
    static RenderWindow* win;
    
    /**
     * @brief The current Map
     * 
     * ...Read the brief.
     */
    static Map* cmap;
    
    /**
     * @brief Cached Map image
     * 
     * ...Read the brief.
     */
    static sf::Image* mapImage;
    
    /**
     * @brief If the MapManager has changed, this is true.
     * 
     * ...Read the brief.
     */
    static bool changed;
};

#endif // MAPMANAGER_H

