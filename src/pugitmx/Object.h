#ifndef __OBJECT_H_
#define __OBJECT_H_

#include <map>
#include "../helplib/stringh.h"
#include "square.h"
#include "Polygon.h"

namespace pugitmx
{
class Object
{
public:
    Object() : _object(0, 0, 0, 0) {};
    Object(std::string nme, std::string typ, int gd, int x, int y, int wd, int ht, bool ellips, Polygon plgn) : name(nme), type(typ), gid(gd), _object(x, y, wd, ht), ellipse(ellips), polygon(plgn) {};
    std::string getName() const;
    std::string getType() const;
    int getGid() const;
    int getObjectX() const;
    int getObjectY() const;
    int getObjectWidth() const;
    int getObjectHeight() const;
    bool isEllipse() const;
    Polygon getPolygon() const;
    void registerProperty(std::string, std::string);
    std::string getProperty(std::string) const;
private:
    std::string name;
    std::string type;
    int gid;
    Square _object;
    std::map<std::string, std::string> properties;
    bool ellipse;
    Polygon polygon;
};
};

#endif // __OBJECT_H_
