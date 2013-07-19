#ifndef _RPGEOM_TILE_H
#define _RPGEOM_TILE_H

#include <string>
#include "Point.h"

namespace rpgeom
{
	namespace internal
	{
		struct Tile
		{
			Point topleft;
			Point topright;
			Point bottomleft;
			Point bottomright;
		};
	};
	
	class Tile
	{
		public:
			Tile(Point,unsigned int,unsigned int);
			Tile(Point,unsigned int);
			Tile(Point,Point,Point,Point);
			void setName(std::string);
			std::string getName() const;
			void setLocation(Point);
			Point getLocation() const;
			bool isInside(Point);
			bool operator==(const Tile&);
			void moveLeft();
			void moveRight();
			void moveUp();
			void moveDown();
			void moveX(int);
			void moveY(int);
		private:
			internal::Tile data;
			unsigned int width;
			unsigned int height;
			Point topleftlocation;
			std::string name;
	};
};

#endif // _RPGEOM_TILE_H
