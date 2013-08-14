#include "Map.h"
#include "GameManager.h"
#include "../helplib/Log.h"

Map::Map()
{
	imapName = "";
	imap = new pugitmx::Map(1.0, "orthogonal", 0, 0, 0, 0);
	imageLoader.setReleaseStrategy(thor::Resources::AutoRelease);
	change = true;
}

Map::Map(std::string mapFileName)
{
	imapName = mapFileName;
	imap = pugitmx::Parser::parseMap(GameManager::getGameFolderName() + returnMapPathWithMap());
	imageLoader.setReleaseStrategy(thor::Resources::AutoRelease);
	change = true;	
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
	tilesets.clear();
	for(std::list<pugitmx::Tileset>::iterator iter = imap->returnTilesetsIteratorB(); iter != imap->returnTilesetsIteratorE(); iter++)
	{
		const pugitmx::Image& im(iter->getImage());
		disandria::Tileset* tlst = new disandria::Tileset;
		tlst->firstgid = iter->getFirstGid();
		tlst->tilewidth = iter->getTileWidth();
		tlst->tileheight = iter->getTileHeight();
		tlst->img = imageLoader.acquire(thor::Resources::fromFile<sf::Image>(GameManager::getGameFolderName() + returnMapPath() + im.getSourceString()));
		std::string color = im.getTrans();
		if(color != "")
		{
			tlst->img->createMaskFromColor(sf::Color(NString::fromHex(color.substr(0,2)),
						NString::fromHex(color.substr(2,2)),
						NString::fromHex(color.substr(4,2))));
		}
		tilesets.push_back(tlst);
	}
	if(change && imapName != "")
	{
		mapPicture.create(imap->getWidth() * imap->getTileWidth(), imap->getHeight() * imap->getTileHeight());
		for(std::list<pugitmx::TileLayer>::iterator iter = imap->returnTileLayersIteratorB(); iter != imap->returnTileLayersIteratorE(); iter++)
		{
			unsigned int image_x = 0;
			unsigned int image_y = 0;
			unsigned int width = iter->getWidth() * imap->getTileWidth();
			unsigned int height = iter->getHeight() * imap->getTileHeight();
			for(int i = 0; i < ((width / imap->getTileWidth()) * (height / imap->getTileHeight())); i++)
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
					mapPicture.copy(*tlst->img, image_x, image_y, sf::IntRect(picture_x * imap->getTileWidth(), picture_y * imap->getTileHeight(), tlst->tilewidth, tlst->tileheight));
				}
				else
				{
					tlst = new disandria::Tileset;
					tlst->tilewidth = imap->getTileWidth();
					tlst->tileheight = imap->getTileHeight();
				}
				image_x += tlst->tilewidth;
				if(width <= image_x)
				{
					image_x = 0;
					image_y += tlst->tileheight;
					if(height < image_y)
					{
						//break;
						return NULL;
					}
				}
			}
		}
		change = false;
		return &mapPicture;
	}
	else if(imapName == "")
	{
		return NULL;
	}
	else
	{
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

void Map::clearShader()
{
	delete mapShader;
	mapShader = NULL;
}
