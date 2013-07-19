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

		bool operator==(const Point& point)
		{
			if(this->x == point.x)
			{
				if(this->y == point.y)
				{
					return true;
				}
			}
			return false;
		}
		
		bool operator>(const Point& point)
		{
			if(this->x > point.x)
			{
				if(this->y > point.y)
				{
					return true;
				}
			}
			return false;
		}

		bool operator<(const Point& point)
		{
			if(this->x < point.x)
			{
				if(this->y < point.y)
				{
					return true;
				}
			}
			return false;
		}
		
		bool operator>=(const Point& point)
		{
			if(this->x >= point.x)
			{
				if(this->y >= point.y)
				{
					return true;
				}
			}
			return false;
		}

		bool operator<=(const Point& point)
		{
			if(this->x <= point.x)
			{
				if(this->y <= point.y)
				{
					return true;
				}
			}
			return false;
		}
	};
};

#endif // _RPGEOM_POINT_H
