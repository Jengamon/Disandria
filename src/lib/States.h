#ifndef STATES_H
#define STATES_H

#include <Poco/Platform.h>

#ifdef POCO_OS_FAMILY_WINDOWS
	#undef VOID
#endif

namespace disandria
{
namespace States
{
enum State {
    VOID,
    MAINMENU,
    MAINGAME
};
};
};

#endif // STATES_H
