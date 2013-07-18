#include "Tile.h"
using namespace rpgeom;

Tile::Tile(std::vector<Point>& pointList)
{
	for(int i = 0; i < pointList.size(); i++)
	{
		points.push_back(pointList[i]);
	}
}

Tile::Tile(Point* pointList, int numberOfPoints)
{
	for(int i = 0; i < numberOfPoints; i++)
	{
		points.push_back(pointList[i]);
	}
}

int Tile::getPointCount() const
{
	return points.size();
}

void Tile::addPoint(Point& point)
{
	points.push_back(point);
}

void Tile::clearPoints()
{
	points.clear();
}

TileData Tile::getPoints()
{
	TileData data;
	data.totalPoints = getPointCount();
	data.data = points.data();
	return data;
}

Point* Tile::operator[] (int index)
{
	return getPoint(index);
}

Point* Tile::getPoint(int index)
{
	return &points[index];
}
