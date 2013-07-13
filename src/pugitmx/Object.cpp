#include "Object.h"

using namespace pugitmx;

std::string Object::getName() const
{
	return name;
}

std::string Object::getType() const
{
	return type;
}

int Object::getGid() const
{
	return gid;
}

bool Object::isEllipse() const
{
	return ellipse;
}

Polygon Object::getPolygon() const
{
	return polygon;
}

int Object::getObjectX() const
{
	return _object.x;
}

int Object::getObjectY() const
{
	return _object.y;
}

int Object::getObjectWidth() const
{
	return _object.width;
}

int Object::getObjectHeight() const
{
	return _object.height;
}

void Object::registerProperty(std::string key, std::string value)
{
	properties[key] = value;
}

std::string Object::getProperty(std::string key) const
{
	if(properties.find(key) == properties.end())
	{
		return "";
	}
	else
	{
		return properties.find(key)->second;
	}
}
