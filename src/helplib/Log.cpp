#include "Log.h"
#include <cstdlib>
#include <Poco/Logger.h>

using namespace Poco;

AutoPtr<FileChannel> Log::fChan = new FileChannel;
AutoPtr<ConsoleChannel> Log::conChan = new ConsoleChannel;
AutoPtr<SplitterChannel> Log::sChan = new SplitterChannel;
bool Log::stp = false;

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
		Logger::root().information("---Loaded logging...---\nDisandria Logger -- Version 0.02\n--------------------");
		Logger::root().setChannel(sChan);
		stp = true;
	}
}

void Log::log(PE::Logging::Levels lv, std::string str)
{
	setup();
	switch(lv)
	{
		case PE::Logging::INFORMATION:
			str = "INFORMATION: " + str;
			Logger::root().information(str.c_str());
			break;
		case PE::Logging::NOTICE:
			str = "NOTICE: " + str;
			Logger::root().information(str.c_str());
			break;
		case PE::Logging::WARNING:
			str = "WARNING: " + str;
			Logger::root().warning(str.c_str());
			break;
		case PE::Logging::ERROR:
			str = "ERROR: " + str;
			Logger::root().error(str.c_str());
			exit(-1);
		case PE::Logging::VOID:
			Logger::root().error(str.c_str());
			break;
	}
}

void Log::log(std::string str)
{
	setup();
	str = "ERROR: " + str;
	Logger::root().error(str.c_str());
	exit(-1);
}
