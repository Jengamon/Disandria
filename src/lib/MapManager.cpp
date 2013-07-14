#include "MapManager.h"
#include "GameManager.h"
#include "../helplib/Log.h"

sf::Image MapManager::im;
pugitmx::Map* MapManager::currentMap;
RenderWindow* MapManager::win;

void MapManager::setRenderWindow(RenderWindow* _win)
{
	win = _win;
}

void MapManager::bakeMap()
{
	if(currentMap != MapParser::getCurrentMap())
	{
		std::list<disandria::Tileset*> tilesets;
		currentMap = MapParser::getCurrentMap();
		im.create(currentMap->getWidth() * currentMap->getTileWidth(),
				currentMap->getHeight() * currentMap->getTileHeight());
		for(std::list<pugitmx::Tileset>::iterator iter = currentMap->returnTilesetsIteratorB(); iter != currentMap->returnTilesetsIteratorE(); iter++)
		{
			const pugitmx::Image& im(iter->getImage());
			disandria::Tileset* tlst = new disandria::Tileset;
			tlst->firstgid = iter->getFirstGid();
			tlst->tilewidth = iter->getTileWidth();
			tlst->tileheight = iter->getTileHeight();
			sf::Image* imx = new sf::Image;
			imx->loadFromFile(GameManager::getGameFolderName() + "maps/" + MapParser::getMapName() + "/" + im.getSourceString());
			std::string color = im.getTrans();
			if(color != "")
			{
				imx->createMaskFromColor(sf::Color(NString::fromHex(color.substr(0,2)),
							NString::fromHex(color.substr(2,2)),
							NString::fromHex(color.substr(4,2))));
			}
			tlst->img = imx;
			tilesets.push_back(tlst);
		}
		for(std::list<pugitmx::TileLayer>::iterator iter = currentMap->returnTileLayersIteratorB(); iter != currentMap->returnTileLayersIteratorE(); iter++)
		{
			unsigned int image_x = 0;
			unsigned int image_y = 0;
			unsigned int width = iter->getWidth() * currentMap->getTileWidth();
			unsigned int height = iter->getHeight() * currentMap->getTileHeight();
			for(int i = 0; i < ((width / currentMap->getTileWidth()) * (height / currentMap->getTileHeight())); i++)
			{
				pugitmx::Tile* tile = iter->findTileByLocation(i);
				disandria::Tileset* tlst;
				for(std::list<disandria::Tileset*>::iterator tlsts = tilesets.begin(); tlsts != tilesets.end(); tlsts++)
				{
					if((*tlsts)->firstgid > tile->getGid())
					{
						break;
					}
					tlst = *tlsts;
				}
				int picture_x = 0;
				int picture_y = 0;
				for(int i = 0; i < (tile->getGid() - (tlst->firstgid)); i++)
				{
					picture_x += currentMap->getTileWidth();
					if(picture_x > (iter->getWidth() * currentMap->getTileWidth()))
					{
						picture_x = 0;
						picture_y += currentMap->getTileHeight();
						if(picture_y > (iter->getHeight() * currentMap->getTileHeight()))
						{
							break;
						}
					}
				}
				im.copy(*tlst->img, image_x, image_y, sf::IntRect(picture_x, picture_y, tlst->tilewidth, tlst->tileheight));
				image_x += tlst->tilewidth;
				if(width <= image_x)
				{
					image_x = 0;
					image_y += tlst->tileheight;
					if(height <= image_y)
					{
						return;
					}
				}
			}
		}
	}
}
		
void MapManager::renderMap()
{ 
	bakeMap();
	sf::Sprite spr;
	sf::Texture tex;
	tex.loadFromImage(im);
	tex.setSmooth(true);
	spr.setTexture(tex);
	spr.setOrigin(spr.getLocalBounds().width / 2, spr.getLocalBounds().height / 2);
	spr.setPosition(win->getSize().x / 2, win->getSize().y / 2);
	win->render(spr);
}
