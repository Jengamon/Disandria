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
		thor::ResourceCache<sf::Image> imageLoader;
		imageLoader.setReleaseStrategy(thor::Resources::AutoRelease);
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
			tlst->img = imageLoader.acquire(thor::Resources::fromFile<sf::Image>(GameManager::getGameFolderName() + "maps/" + MapParser::getMapName() + "/" + im.getSourceString()));
			std::string color = im.getTrans();
			if(color != "")
			{
				tlst->img->createMaskFromColor(sf::Color(NString::fromHex(color.substr(0,2)),
							NString::fromHex(color.substr(2,2)),
							NString::fromHex(color.substr(4,2))));
			}
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
				disandria::Tileset* tlst = NULL;
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
				if(tile->getGid() > 0)
				{
					for(int il = 0; il < (tile->getGid() - (tlst->firstgid)); il++)
					{
						picture_x++;
						if(picture_x >= (int(tlst->img->getSize().x) / tlst->tilewidth))
						{
							picture_x = 0;
							picture_y++;
							if(picture_y >= (int(tlst->img->getSize().y) / tlst->tileheight))
							{
								break;
							}
						}
					}
					im.copy(*tlst->img, image_x, image_y, sf::IntRect(picture_x * currentMap->getTileWidth(), picture_y * currentMap->getTileHeight(), tlst->tilewidth, tlst->tileheight));
				}
				else
				{
					tlst = new disandria::Tileset;
					tlst->tilewidth = currentMap->getTileWidth();
					tlst->tileheight = currentMap->getTileHeight();
				}
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
	thor::BigSprite spr;
	thor::BigTexture tex;
	tex.loadFromImage(im);
	tex.setSmooth(true);
	spr.setTexture(tex);
	spr.setOrigin(spr.getLocalBounds().width / 2, spr.getLocalBounds().height / 2);
	spr.setPosition(win->getSize().x / 2, win->getSize().y / 2);
	win->render(spr);
}
