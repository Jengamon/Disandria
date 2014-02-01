#include "PropertyList.h"
#include "../../../helplib/stringh.h"
#include <cstdlib>

void PropertyList::addProperty(std::string key, Property::Type tp, std::string vl)
{
    switch(tp) {
    case Property::NUMERIC:
        addNumericProperty(key, atof(vl.c_str()));
        break;
    case Property::STRING:
        addStringProperty(key, vl);
        break;
    case Property::BOOLEAN:
        addBoolProperty(key, BString::fromStringText(vl));
        break;
    };
}

double PropertyList::getNumericProperty(std::string key)
{
    if(doubleProps.find(key) != doubleProps.end()) {
        return doubleProps.find(key)->second;
    }
    return 0.0;
}

std::string PropertyList::getStringProperty(std::string key)
{
    if(stringProps.find(key) != stringProps.end()) {
        return stringProps.find(key)->second;
    }
    return "";
}

bool PropertyList::getBooleanProperty(std::string key)
{
    if(boolProps.find(key) != boolProps.end()) {
        return boolProps.find(key)->second;
    }
    return false;
}

void PropertyList::addNumericProperty(std::string key, double vl)
{
    doubleProps[key] = vl;
}

void PropertyList::addBoolProperty(std::string key, bool vl)
{
    boolProps[key] = vl;
}

void PropertyList::addStringProperty(std::string key, std::string vl)
{
    stringProps[key] = vl;
}
