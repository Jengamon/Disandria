#ifndef MAPPARSER_H
#define MAPPARSER_H

#include "../pugitmx/Parser.h"

class MapParser
{
	public:
		static void loadCurrentMap(std::string);
		static pugitmx::Map* getCurrentMap();
		static std::string getMapName();
	private:
		static pugitmx::Map* currentMap;
		static std::string mapname;
};

#endif // MAPPARSER_H
