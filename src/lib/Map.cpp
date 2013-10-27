#include "Map.h"
#include "GameManager.h"
#include "../helplib/Log.h"

Map::Map()
{
    imapName = "";
    imap = new pugitmx::Map(1.0, "orthogonal", 0, 0, 0, 0);
    imageLoader.setReleaseStrategy(thor::Resources::AutoRelease);
    change = true;
    createMap();
}

Map::Map(std::string mapFileName)
{
    imapName = mapFileName;
    imap = pugitmx::Parser::parseMap(GameManager::getGameFolderName() + returnMapPathWithMap());
    imageLoader.setReleaseStrategy(thor::Resources::AutoRelease);
    change = true;
    createMap();
}

std::string Map::returnMapPath()
{
    return ("maps/" + imapName + "/");
}

std::string Map::returnMapPathWithMap()
{
    return ("maps/" + imapName + "/" + imapName + ".tmx");
}

std::string Map::returnMapName()
{
    return imapName;
}

pugitmx::Map* Map::returnMap() const
{
    return imap;
}

sf::Image* Map::renderMap()
{
    /* Clears the tileset list, and grabs the tilesets */
    tilesets.clear();
    for(std::list<pugitmx::Tileset>::iterator iter = imap->returnTilesetsIteratorB(); iter != imap->returnTilesetsIteratorE(); iter++) {
        const pugitmx::Image& im(iter->getImage());
        disandria::Tileset* tlst = new disandria::Tileset;
        tlst->firstgid = iter->getFirstGid();
        tlst->tilewidth = iter->getTileWidth();
        tlst->tileheight = iter->getTileHeight();
        /* Preloads image for tileset */
        tlst->img = imageLoader.acquire(thor::Resources::fromFile<sf::Image>(GameManager::getGameFolderName() + returnMapPath() + im.getSourceString()));
        /* Check for transparency, and if any, apply it */
        std::string color = im.getTrans();
        if(color != "") {
            tlst->img->createMaskFromColor(sf::Color(NString::fromHex(color.substr(0, 2)),
                                           NString::fromHex(color.substr(2, 2)),
                                           NString::fromHex(color.substr(4, 2))));
        }
        tilesets.push_back(tlst);
    }

    if(change && imapName != "") {

        for(std::list<pugitmx::TileLayer>::iterator iter = imap->returnTileLayersIteratorB(); iter != imap->returnTileLayersIteratorE(); iter++) {
            createTileLayer(*iter);
            renderTiles();
            clearTileLayer();
        }
        change = false;
        return renderTiles();
    } else if(imapName == "") {
        return NULL;
    } else {
        return &mapPicture;
    }
}

sf::Shader* Map::getShader()
{
    return mapShader;
}

void Map::setShader(sf::Shader* shd)
{
    clearShader();
    mapShader = shd;
}

disandria::Tileset* Map::findTileTileset(pugitmx::Tile& tile)
{
    disandria::Tileset* tileset = NULL;
    for(std::list<disandria::Tileset*>::iterator tlsts = tilesets.begin(); tlsts != tilesets.end(); tlsts++) {
        if((*tlsts)->firstgid > tile.getGid()) {
            break;
        }
        tileset = *tlsts;
    }
    return tileset;
}

sf::Vector2i Map::findTilesetTileLocation(pugitmx::Tile& tile, disandria::Tileset& tileset)
{
    int picture_x = 0;
    int picture_y = 0;
    for(int il = 0; il < (tile.getGid() - (tileset.firstgid)); il++) {
        picture_x++;
        if(picture_x >= (int(tileset.img->getSize().x) / tileset.tilewidth)) {
            picture_x = 0;
            picture_y++;
            if(picture_y >= (int(tileset.img->getSize().y) / tileset.tileheight)) {
                break;
            }
        }
    }
    return sf::Vector2i(picture_x, picture_y);
}

sf::Image* Map::createTileLayer(pugitmx::TileLayer& tly)
{
    int currentTile = 0;
    for(std::list<pugitmx::Tile>::iterator tliter = tly.grabTilesIteratorB(); tliter != tly.grabTilesIteratorE(); tliter++) {
        pugitmx::Tile* tile = &*tliter;
        disandria::Tileset* tileset = findTileTileset(*tile);
        sf::Vector2i loc;
        bool genLoc = false;
        if(tileset != NULL)
            loc = findTilesetTileLocation(*tile, *tileset);
        else
            genLoc = true;
        sf::Image* newMapTileImage = new sf::Image;
        if(genLoc) {
            newMapTileImage->create(imap->getTileWidth(), imap->getTileHeight(), sf::Color::Black);
            tiles[currentTile++] = new MapTile(NULL, imap->getTileWidth(), imap->getTileHeight());
        } else {
            newMapTileImage->create(tileset->tilewidth, tileset->tileheight);
            newMapTileImage->copy(*tileset->img, 0, 0, sf::IntRect(loc.x * tileset->tilewidth, loc.y * tileset->tileheight, tileset->tilewidth, tileset->tileheight));
            tiles[currentTile++] = new MapTile(newMapTileImage, tileset->tilewidth, tileset->tileheight);
        }
        //TODO: Add actor rendering code here
        newMapTileImage = NULL;
    }
}

void Map::clearTileLayer()
{
    for(std::map<int, MapTile*>::iterator iter = tiles.begin(); iter != tiles.end(); iter++) {
        if(iter->second != NULL)
            delete iter->second;
    }
    tiles.clear();
}

void Map::createMap()
{
    mapPicture.create(imap->getWidth() * imap->getTileWidth(), imap->getHeight() * imap->getTileHeight());
}

sf::Image* Map::renderTiles()
{
    for(std::map<int, MapTile*>::iterator iter = tiles.begin(); iter != tiles.end(); iter++) {
        int renderPosInt = iter->first;
        MapTile* tileToRender = iter->second;
        sf::Vector2i renderPos(renderPosInt % imap->getWidth(), renderPosInt / imap->getHeight());
        if(tileToRender->renderTile() != NULL) {
            mapPicture.copy(*tileToRender->renderTile(), renderPos.x * imap->getTileWidth(), renderPos.y * imap->getTileHeight());
        }
    }
    return &mapPicture;
}

void Map::clearShader()
{
    delete mapShader;
    mapShader = NULL;
}

Map::~Map()
{
    clearTileLayer();
}
