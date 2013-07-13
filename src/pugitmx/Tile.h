#ifndef __TILE_H_
#define __TILE_H_

#include "../helplib/stringh.h"
#include "square.h"

namespace pugitmx
{
	class Tile
	{
		public:
			Tile() {};
			Tile(int gd) : gid(gd){};
			int getGid() const;
		private:
			int gid;
	};
};

#endif // __TILE_H_
