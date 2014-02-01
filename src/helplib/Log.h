#ifndef __LOG_H_
#define __LOG_H_

#include <Poco/AutoPtr.h>
#include <Poco/ConsoleChannel.h>
#include <Poco/FileChannel.h>
#include <Poco/SplitterChannel.h>
#include <Poco/Platform.h>
#include <map>

#ifdef POCO_OS_FAMILY_WINDOWS
#undef ERROR
#undef VOID
#endif

namespace PE
{
namespace Logging
{
enum Levels {
    ERROR,
    WARNING,
    NOTICE,
    INFORMATION,
    VOID
};
};
};

class Log
{
public:
    static void log(PE::Logging::Levels, std::string, int = 0);
    static void log(std::string, int = 0);
    static int registerId(std::string);
private:
    static Poco::AutoPtr<Poco::FileChannel> fChan;
    static Poco::AutoPtr<Poco::ConsoleChannel> conChan;
    static Poco::AutoPtr<Poco::SplitterChannel> sChan;
    static void setup();
    static bool stp;
    static std::map<int, std::string> ids;
};


#endif // __LOG_H_
