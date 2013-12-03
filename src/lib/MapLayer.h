#ifndef __MAPLAYER_DISANDRIA_H
#define __MAPLAYER_DISANDRIA_H

#include <map>
#include <cassert>
#include <SFML/Graphics.hpp>
#include "../pugitmx/TileLayer.h"
#include "TilesetManager.h"
#include "MapTile.h"

class MapLayer
{
public:
	/**
	 * @brief Create a MapLayer
	 * @param xml TileLayer to based MapLayer off of
	 * @param mtlwd Map tile width
	 * @param mtlht Map tile height
	 * @param man Pointer to TilesetManager, where tilesets have been preloaded.
	 * 
	 * Creates a MapLayer, which renders a pugitmx::TileLayer
	 */
    MapLayer(pugitmx::TileLayer xml, unsigned int mtlwd, unsigned int mtlht, TilesetManager* man) : xmlInfo(xml), maptilewidth(mtlwd), maptileheight(mtlht), tlman(man), genIm(NULL) {
        assert(man != NULL);
    }
    
    /**
     * @brief Render a MapLayer
     * 
     * Render the MapLayer to an Image
     */
    sf::Image* renderLayer();
    
    /**
     * @brief Cleanup
     * 
     * Clean up MapLayer, so that memory isn't wasted
     */
    ~MapLayer();
private:
    unsigned int maptilewidth;
    unsigned int maptileheight;
    TilesetManager* tlman;
    pugitmx::TileLayer xmlInfo;
    std::map<int, MapTile*> tiles;
    sf::Image* genIm;
    static sf::Vector2i findTileLocationInTileset(unsigned int, disandria::Tileset&);
    void genImage();
};

#endif // __MAPLAYER_DISANDRIA_H
