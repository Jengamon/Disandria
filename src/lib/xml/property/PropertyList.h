#ifndef __DISANDRIA_PROPERTYLIST_H
#define __DISANDRIA_PROPERTYLIST_H

#include <map>
#include <string>

namespace Property
{
enum Type {
    NUMERIC,
    STRING,
    BOOLEAN,
    NIL
};
};

class PropertyList
{
public:
    void addProperty(std::string, Property::Type, std::string);
    double getNumericProperty(std::string);
    std::string getStringProperty(std::string);
    bool getBooleanProperty(std::string);
    void addNumericProperty(std::string, double);
    void addBoolProperty(std::string, bool);
    void addStringProperty(std::string, std::string);
private:
    std::map<std::string, double> doubleProps;
    std::map<std::string, std::string> stringProps;
    std::map<std::string, bool> boolProps;
};

#endif // __DISANDRIA_PROPERTYLIST_H
