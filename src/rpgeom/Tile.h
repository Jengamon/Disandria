#ifndef _RPGEOM_TILE_H
#define _RPGEOM_TILE_H

#include <vector>
#include "Point.h"
#include "TileData.h"

namespace rpgeom
{
	class Tile
	{
		public:
			Tile(std::vector<Point>&);
			Tile(Point[], int);
			int getPointCount() const;
			void addPoint(Point&);
			void clearPoints();
			TileData getPoints();
			Point* operator[] (int index);
			Point* getPoint(int index);
		private:
			std::vector<Point> points;
	};
};

#endif // _RPGEOM_TILE_H
