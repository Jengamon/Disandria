#ifndef __DISANDRIA_BASEOBJECT_H
#define __DISANDRIA_BASEOBJECT_H

#include "property/PropertyList.h"

namespace Object
{
	enum Type
	{
		ACTOR,
		CHARACTER,
		CLASS,
		ITEM,
		SKILL
	};
};

class BaseObject
{
	public:
		virtual Object::Type type() = 0;
		virtual void setName(std::string);
		virtual void addProperty(std::string, std::string, std::string);
		virtual std::string getName();
		virtual double getNumericProperty(std::string);
		virtual bool getBooleanProperty(std::string);
		virtual std::string getStringProperty(std::string);
	protected:
		PropertyList propList;
		std::string name;
		static Property::Type convertStringToType(std::string);
};

#endif // __DISANDRIA_BASEOBJECT_H
