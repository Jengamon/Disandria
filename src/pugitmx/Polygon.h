#ifndef __POLYGON_H_
#define __POLYGON_H_

#include "../helplib/stringh.h"

namespace pugitmx
{
	class Polygon
	{
		public:
			Polygon() {}
			Polygon(std::string pint) : points(pint) {}
			std::string getPoints() const;
		private:
			std::string points;
	};
};

#endif // __POLYGON_H_
