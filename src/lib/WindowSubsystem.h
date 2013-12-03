#ifndef __DISANDRIA_WINDOWSUBSYSTEM_H
#define __DISANDRIA_WINDOWSUBSYSTEM_H

#include <Poco/Util/Subsystem.h>
#include "RenderWindow.h"

class WindowSubsystem : public Poco::Util::Subsystem
{
	/**
	 * @brief Initialize the WindowSubsystem
	 * @param app Application to initialize
	 * 
	 * Initializes the WindowSubsystem of Disandria
	 */
    void initialize(Poco::Util::Application& app);
    
    /**
     * @brief Uninitialize the WindowSubsystem
     * 
     * Uninitialize the WindowSubsystem. Performs any required cleanup.
     */
    void uninitialize();
    
    /**
     * @brief Define command-line options for the WindowSubsystem
     * @param opst OptionSet to write options to
     * 
     * Make command-line control of the WindowSubsystem possible
     */
    void defineOptions(Poco::Util::OptionSet& opst);
    
    /**
     * @brief Name of WindowSubsystem
     * 
     * ...What do you expect?
     */
    const char* name() const;
};

#endif // __DISANDRIA_WINDOWSUBSYSTEM_H
