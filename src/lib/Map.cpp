#include "Map.h"
#include "GameManager.h"
#include "../helplib/Log.h"

Map::Map()
{
    imapName = "";
    imap = new pugitmx::Map(1.0, "orthogonal", 0, 0, 0, 0);
}

Map::Map(std::string mapFileName)
{
    imapName = mapFileName;
    imap = pugitmx::Parser::parseMap(GameManager::getGameFolderName() + returnMapPathWithMap());
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
    for(auto iter = imap->returnTilesetsIteratorB(); iter != imap->returnTilesetsIteratorE(); iter++) {
        const pugitmx::Image& im(iter->getImage());
        tlstman.addTileset(iter->getName(), iter->getFirstGid(), iter->getTileWidth(), iter->getTileHeight(), GameManager::getGameFolderName() + returnMapPath() + im.getSourceString(), [&](sf::Image * img) -> void {
            std::string color = im.getTrans();
            if(color != "")
                img->createMaskFromColor(sf::Color(NString::fromHex(color.substr(0, 2)),
                NString::fromHex(color.substr(2, 2)),
                NString::fromHex(color.substr(4, 2))));
        });
    }

    for(std::list<pugitmx::TileLayer>::iterator iter = imap->returnTileLayersIteratorB(); iter != imap->returnTileLayersIteratorE(); iter++) {
        createTileLayer(*iter);
    }
    return &mapPicture;
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

sf::Image* Map::createTileLayer(pugitmx::TileLayer& tly)
{
    MapLayer tlyr(tly, imap->getTileWidth(), imap->getTileHeight(), &tlstman);
    sf::Image* im = tlyr.renderLayer();
    mapPicture.copy(*im, 0, 0);
    delete im;
}

void Map::clearShader()
{
    delete mapShader;
    mapShader = NULL;
}

Map::~Map()
{
}
