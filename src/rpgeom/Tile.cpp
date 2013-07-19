#include "Tile.h"
using namespace rpgeom;

Tile::Tile(Point topleft, unsigned int _width, unsigned int _height)
{
	data.topleft = topleft;
	data.topright = Point::createPoint(topleft.x + _width, topleft.y);
	data.bottomleft = Point::createPoint(topleft.x, topleft.y + _height);
	data.bottomright = Point::createPoint(topleft.x + _width, topleft.y + _height);
	width = _width;
	height = _height;
}

Tile::Tile(Point topleft, unsigned int _squ)
{
	data.topleft = topleft;
	data.topright = Point::createPoint(topleft.x + _squ, topleft.y);
	data.bottomleft = Point::createPoint(topleft.x, topleft.y + _squ);
	data.bottomright = Point::createPoint(topleft.x + _squ, topleft.y + _squ);
	width = _squ;
	height = _squ;
}

Tile::Tile(Point topleft, Point topright, Point bottomright, Point bottomleft)
{
	data.topleft = topleft;
	data.topright = topright;
	data.bottomright = bottomright;
	data.bottomleft = bottomleft;
	width = topright.x - topleft.x;
	height = bottomleft.y - topleft.y; 
}

void Tile::setName(std::string nm)
{
	name = nm;
}

std::string Tile::getName() const
{
	return name;
}

void Tile::setLocation(Point tll)
{
	topleftlocation = tll;
}
			
Point Tile::getLocation() const
{
	return topleftlocation;
}

bool Tile::isInside(Point point)
{	
	if(point >= data.topleft)
	{
		if(point <= data.bottomright)
		{
			return true;
		}
	}
	return false;
}

bool Tile::operator==(const Tile& right)
{
	if(this->data.topleft == right.data.topleft)
	{
		if(this->data.topright == right.data.topright)
		{
			if(this->data.bottomright == right.data.bottomright)
			{
				if(this->data.bottomleft == right.data.bottomleft)
				{
					return true;
				}
			}
		}
	}
	return false;
}

void Tile::moveLeft()
{
	topleftlocation.x -= width;
}

void Tile::moveRight()
{
	topleftlocation.x += width;
}

void Tile::moveUp()
{
	topleftlocation.y -= height;
}

void Tile::moveDown()
{
	topleftlocation.y += height;
}

void Tile::moveX(int by)
{
	topleftlocation.x += by;
}

void Tile::moveY(int by)
{
	topleftlocation.y += by;
}
