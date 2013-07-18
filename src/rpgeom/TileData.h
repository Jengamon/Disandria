#ifndef _RPGEOM_TILEDATA_H
#define _RPGEOM_TILEDATA_H

namespace rpgeom
{
	class TileData
	{
		friend class Tile;
		public:
			Point* operator[] (int where)
			{
				if(where < 0 || where > totalPoints)
				{
					return nullptr;
				}
				Point* ret = data;
				for(int i = 1; i < where; i++)
				{
					ret++;
				}
				return ret;
			}
		private:
			int totalPoints;
			Point* data;
	};
};

#endif // _RPGEOM_TILEDATA_H
