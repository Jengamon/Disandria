#include "BaseObject.h"

Property::Type BaseObject::convertStringToType(std::string tp)
{
	if(tp == "NUMERIC")
		return Property::NUMERIC;
	else if(tp == "STRING")
		return Property::STRING;
	else if(tp == "BOOLEAN")
		return Property::BOOLEAN;
	else
		return Property::NIL;
}

void BaseObject::setName(std::string nm)
{
	name = nm;
}

void BaseObject::addProperty(std::string key, std::string tp, std::string vl)
{
	propList.addProperty(key, convertStringToType(tp), vl);
}

std::string BaseObject::getName()
{
	return name;
}

double BaseObject::getNumericProperty(std::string key)
{
	return propList.getNumericProperty(key);
}

bool BaseObject::getBooleanProperty(std::string key)
{
	return propList.getBooleanProperty(key);
}

std::string BaseObject::getStringProperty(std::string key)
{
	return propList.getStringProperty(key);
}
