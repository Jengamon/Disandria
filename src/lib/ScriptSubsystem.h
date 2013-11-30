#ifndef __DISANDRIA_SCRIPTSUBSYSTEM_H
#define __DISANDRIA_SCRIPTSUBSYSTEM_H

#include <Poco/Util/Subsystem.h>
#include "script/ScriptAPI.h"

class ScriptSubsystem : public Poco::Util::Subsystem
{
private:
    void initialize(Poco::Util::Application&);
    void uninitialize();
    void defineOptions(Poco::Util::OptionSet&);
    const char* name() const;
    /* Members */
public:
    static ScriptAPI* scriptAPI;
};

#endif // __DISANDRIA_SCRIPTSUBSYSTEM_H
