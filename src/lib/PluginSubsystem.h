#ifndef __PLUGINSUBSYSTEM_DISANDRIA_H
#define __PLUGINSUBSYSTEM_DISANDRIA_H

#include <Poco/Util/Subsystem.h>
#include <Poco/ClassLoader.h>
#include <Poco/Manifest.h>
#include "script/ScriptAPI.h"

using ScriptPluginLoader = Poco::ClassLoader<ScriptAPI>;
using ScriptPluginManifest = Poco::Manifest<ScriptAPI>;

class PluginSubsystem : public Poco::Util::Subsystem
{
		void initialize(Poco::Util::Application&);
		void uninitialize();
		void defineOptions(Poco::Util::OptionSet&);
		const char* name() const;
};

#endif // __PLUGINSUBSYSTEM_DISANDRIA_H
