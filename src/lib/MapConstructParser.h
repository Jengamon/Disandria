#ifndef MAPCONSTRUCTPARSER_H
#define MAPCONSTRUCTPARSER_H

#include <Poco/DOM/DOMParser.h>
#include <Poco/DOM/Document.h>
#include <Poco/DOM/NodeIterator.h>
#include <Poco/DOM/NodeFilter.h>
#include <Poco/DOM/AutoPtr.h>
#include <Poco/SAX/InputSource.h>
#include <fstream>

class MapConstructParser
{
	public:
		static void loadMapConstruct(std::string);
		static std::string returnStartMapName();
	private:
		static Poco::AutoPtr<Poco::XML::Document> construct;
};

#endif // MAPCONSTRUCTPARSER_H
