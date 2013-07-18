#ifndef _RPGEOM_POINT_H
#define _RPGEOM_POINT_H

namespace rpgeom
{
	struct Point
	{
		int x;
		int y;
		static Point createPoint(int x, int y)
		{
			Point xy;
			xy.x = x;
			xy.y = y;
			return xy;
		}
	};
};

#endif // _RPGEOM_POINT_H
