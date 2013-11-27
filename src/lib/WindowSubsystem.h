#ifndef __DISANDRIA_WINDOWSUBSYSTEM_H
#define __DISANDRIA_WINDOWSUBSYSTEM_H

#include <Poco/Util/Subsystem.h>
#include "RenderWindow.h"

class WindowSubsystem : public Poco::Util::Subsystem
{
		void initialize(Poco::Util::Application&);
		void uninitialize();
		void defineOptions(Poco::Util::OptionSet&);
		const char* name() const;
};

#endif // __DISANDRIA_WINDOWSUBSYSTEM_H
