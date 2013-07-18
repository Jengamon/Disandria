#ifndef _RPGEOM_WORLD_H
#define _RPGEOM_WORLD_H

#include <string>

namespace rpgeom
{
	class World
	{
		public:
			World(std::string n) : name(n) {}
			std::string getName();
		private:
			std::string name;
	};
};

#endif // _RPGEOM_WORLD_H
