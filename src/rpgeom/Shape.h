#ifndef _RPGEOM_SHAPE_H
#define _RPGEOM_SHAPE_H

#include <vector>
#include "Point.h"
#include "ShapeData.h"

namespace rpgeom
{
	class Shape
	{
		public:
			Shape(std::vector<Point>&);
			Shape(Point[], int);
			int getPointCount() const;
			void addPoint(Point&);
			void clearPoints();
			ShapeData getPoints();
			Point* operator[] (int index);
			Point* getPoint(int index);
		private:
			std::vector<Point> points;
	};
};

#endif // _RPGEOM_SHAPE_H
