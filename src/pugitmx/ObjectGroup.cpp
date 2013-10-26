#include "ObjectGroup.h"
#include "../helplib/Log.h"

using namespace pugitmx;

std::string ObjectGroup::getName() const
{
    return name;
}

int ObjectGroup::getWidth() const
{
    return width;
}

int ObjectGroup::getHeight() const
{
    return height;
}

void ObjectGroup::registerObject(Object tl)
{
    objects.push_back(tl);
}

std::list<Object> ObjectGroup::grabObjects()
{
    return objects;
}

std::list<Object>::iterator ObjectGroup::grabObjectsIteratorB()
{
    return objects.begin();
}

std::list<Object>::iterator ObjectGroup::grabObjectsIteratorE()
{
    return objects.end();
}

void ObjectGroup::registerProperty(std::string key, std::string value)
{
    properties[key] = value;
}

std::string ObjectGroup::getProperty(std::string key) const
{
    if(properties.find(key) == properties.end()) {
        return "";
    } else {
        return properties.find(key)->second;
    }
}
