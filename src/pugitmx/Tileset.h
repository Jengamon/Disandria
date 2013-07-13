#ifndef __TILESET_H_
#define __TILESET_H_

#include "../helplib/stringh.h"
#include "Image.h"
#include <map>
#define uint unsigned int

namespace pugitmx
{
	struct TilePropertyKey
	{
		int id;
		std::string propertyname;
	};

	class Tileset
	{
		public:
			Tileset() {};
			Tileset(uint fgd, std::string nme, uint tlwd, uint tlht, Image srcim) : firstgid(fgd), name(nme), tilewidth(tlwd), tileheight(tlht), image(srcim) {};
			uint getFirstGid() const;
			std::string getName() const;
			uint getTileWidth() const;
			uint getTileHeight() const;
			Image getImage() const;
			void registerProperty(TilePropertyKey,std::string);
			std::string getProperty(TilePropertyKey) const;
		private:
			uint firstgid;
			std::string name;
			uint tilewidth;
			uint tileheight;
			Image image;
			std::map<std::string, std::string> properties;
	};
};

#undef uint

#endif // __TILESET_H_
