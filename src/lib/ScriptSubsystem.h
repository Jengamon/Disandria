#ifndef __DISANDRIA_SCRIPTSUBSYSTEM_H
#define __DISANDRIA_SCRIPTSUBSYSTEM_H

#include <Poco/Util/Subsystem.h>
#include "script/ScriptAPI.h"

class ScriptSubsystem : public Poco::Util::Subsystem
{
private:
	/**
	 * @brief Initialize the ScriptSubsystem
	 * 
	 * Initializes the ScriptSubsystem. Then bakes you potatoes.
	 * Then eats those potatoes and hides the dishes.
	 */
    void initialize(Poco::Util::Application&);
    
    /**
     * @brief Uninitialize the ScriptSubsystem
     * 
     * Uninitializes the ScriptSubsystem. And dies with all off it's secrets.
     * (-_-;)
     */
    void uninitialize();
    /**
     * @brief Makes the command-line control of the ScriptSubsystem possible
     * @param opst OptionSet to write options to
     * 
     * Magic...Not really. Look at WindowSubsystem::defineOptions()
     * @todo Stop being lazy, and Ctrl+C!
     */
    void defineOptions(Poco::Util::OptionSet& opst);
    
    /**
     * @brief Name of ScriptSubsystem
     * 
     * Honestly, what did you expect, a parade?....
     */
    const char* name() const;
    /* Members */
public:
	/**
	 * @brief The ScriptAPI through which all scripts are channeled through
	 * 
	 * The master script executor. Kinda like the Master Sword, except for scripts.
	 * And the fact that it isn't as cool. Or shiny. Or swordy.
	 */
    static ScriptAPI* scriptAPI;
};

#endif // __DISANDRIA_SCRIPTSUBSYSTEM_H
