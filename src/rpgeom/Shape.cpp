#include "Shape.h"
using namespace rpgeom;

Shape::Shape(std::vector<Point>& pointList)
{
	for(int i = 0; i < pointList.size(); i++)
	{
		points.push_back(pointList[i]);
	}
}

Shape::Shape(Point* pointList, int numberOfPoints)
{
	for(int i = 0; i < numberOfPoints; i++)
	{
		points.push_back(pointList[i]);
	}
}

int Shape::getPointCount() const
{
	return points.size();
}

void Shape::addPoint(Point& point)
{
	points.push_back(point);
}

void Shape::clearPoints()
{
	points.clear();
}

ShapeData Shape::getPoints()
{
	ShapeData data;
	data.totalPoints = getPointCount();
	data.data = points.data();
	return data;
}

Point* Shape::operator[] (int index)
{
	return getPoint(index);
}

Point* Shape::getPoint(int index)
{
	return &points[index];
}
