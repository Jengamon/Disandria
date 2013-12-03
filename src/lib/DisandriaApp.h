#ifndef __DISANDRIAAPP_DISANDRIA_H
#define __DISANDRIAAPP_DISANDRIA_H

#include <Poco/Util/Application.h>
#include "RenderWindow.h"

class DisandriaApp : public Poco::Util::Application
{
private:
	/**
	 * @brief Initialize the application (start Disandria)
	 * @param app Application to initialize
	 * 
	 * Initialize the application. This is the initializer that starts and loads all subsystems
	 * to get Disandria running.
	 */
    void initialize(Poco::Util::Application& app);
    
    /**
     * @brief Reinitialize the application
     * @param app Application to reinitialize
     * 
     * Reinitializes the application. Not used yet.
     */
    void reinitialize(Poco::Util::Application& app);
    
    /**
     * @brief Uninitializes and cleans up application
     * 
     * Cleans up Disandria, as to not leave a mess.
     */
    void uninitialize();
    
    /**
     * @brief Defines command-line options
     * @param optionSet OptionSet to write options to
     * 
     * Makes the command-line control of Disandria in general possible. This
     * function defines basic needed options, such as help and version.
     */
    void defineOptions(Poco::Util::OptionSet& optionSet);
    
    /**
     * @brief Main logic loop
     * @param args List of arguments that are not options.
     * 
     * Main logic loop. This is the Motherboard to Disandria.
     */
    int main(const std::vector<std::string>& args);
    
    /**
     * @brief Name of application
     * 
     * Just a name.
     */
    const char* name() const;
    
	/**
	 * @brief Unknownnnn.....
	 * 
	 * Not much that is needed to be known about this.
	 */
    void handleVersion(const std::string&, const std::string&);
    
    /**
	 * @brief Unknownnnn.....
	 * 
	 * Same here. Look at handleVersion()
	 */
    void handleHelp(const std::string&, const std::string&);
    
    /**
	 * @brief Unknownnnn.....
	 * 
	 * Same here. Look at handleVersion()
	 */
    void displayHelp();
    /* Members */
    /**
     * @brief RenderWindow pointer
     * 
     * Pointer to a RenderWindow, so that it can be accessed by this object.
     * Must be initialized by a WindowSubsystem.
     */
    RenderWindow* rwin;
};

#endif // __DISANDRIAAPP_DISANDRIA_H
