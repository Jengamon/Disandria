#include "Log.h"
#include <cstdlib>
#include <Poco/Logger.h>

using namespace Poco;

AutoPtr<FileChannel> Log::fChan = new FileChannel;
AutoPtr<ConsoleChannel> Log::conChan = new ConsoleChannel;
AutoPtr<SplitterChannel> Log::sChan = new SplitterChannel;
bool Log::stp = false;
std::map<int,std::string> Log::ids;

void Log::setup()
{
	if(!stp)
	{
		fChan->setProperty("path", "./Disandria.log");
		fChan->setProperty("compress", "true");
		fChan->setProperty("archive", "number");
		fChan->setProperty("purgeCount", "50");
		fChan->setProperty("rotation", "2000 K");

		sChan->addChannel(fChan);
		sChan->addChannel(conChan);
	
		Logger::root().setLevel("trace");
		Logger::root().setChannel(fChan);
		Logger::root().information("---Loaded logging...---\nDisandria Logger -- Version 0.1\n--------------------");
		Logger::root().setChannel(sChan);
		stp = true;
	}
}

void Log::log(PE::Logging::Levels lv, std::string str, int id)
{
	setup();
	std::string prefix = "[] ";
	if(id != 0)
	{
		if(ids.find(id) != ids.end())
			prefix = "[" + ids.find(id)->second + "] ";
	}
	switch(lv)
	{
		case PE::Logging::INFORMATION:
			str = "INFORMATION: " + prefix + str;
			Logger::root().information(str.c_str());
			break;
		case PE::Logging::NOTICE:
			str = "NOTICE: " + prefix + str;
			Logger::root().information(str.c_str());
			break;
		case PE::Logging::WARNING:
			str = "WARNING: " + prefix + str;
			Logger::root().warning(str.c_str());
			break;
		case PE::Logging::ERROR:
			str = "ERROR: " + prefix + str;
			Logger::root().error(str.c_str());
			exit(-1);
		case PE::Logging::VOID:
			Logger::root().error(str.c_str());
			break;
	}
}

void Log::log(std::string str, int id)
{
	setup();
	std::string prefix = "[] ";
	if(id != 0)
	{
		if(ids.find(id) != ids.end())
			prefix = "[" + ids.find(id)->second + "] ";
	}
	str = "ERROR: " + prefix + str;
	Logger::root().error(str.c_str());
	exit(-1);
}

int Log::registerId(std::string id)
{
	static int idNum = 1;
	ids[idNum] = id;
	idNum++;
	return idNum;
}
