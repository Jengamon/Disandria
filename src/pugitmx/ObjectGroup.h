#ifndef __OBJECTGROUP_H_
#define __OBJECTGROUP_H_

#include "../helplib/stringh.h"
#include "Object.h"
#include <list>
#include <map>

namespace pugitmx
{
class ObjectGroup
{
public:
    ObjectGroup() {};
    ObjectGroup(std::string nme, int wd, int ht) : name(nme), width(wd), height(ht) {};
    std::string getName() const;
    int getWidth() const;
    int getHeight() const;
    void registerObject(Object);
    std::list<Object> grabObjects();
    std::list<Object>::iterator grabObjectsIteratorB();
    std::list<Object>::iterator grabObjectsIteratorE();
    void registerProperty(std::string, std::string);
    std::string getProperty(std::string) const;
private:
    std::string name;
    int width;
    int height;
    std::map<std::string, std::string> properties;
    std::list<Object> objects;
};
};

#endif // __OBJECTGROUP_H_
