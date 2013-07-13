#include "MapConstructParser.h"

Poco::AutoPtr<Poco::XML::Document> MapConstructParser::construct;

void MapConstructParser::loadMapConstruct(std::string flnm)
{
	std::ifstream in(flnm.c_str());
	Poco::XML::InputSource src(in);

	Poco::XML::DOMParser parser;
	construct = parser.parse(&src);
}

std::string MapConstructParser::returnStartMapName()
{
	Poco::XML::Node* strmp = construct->getNodeByPath("maps/startMap[@name]");
	return strmp->getNodeValue();
}
