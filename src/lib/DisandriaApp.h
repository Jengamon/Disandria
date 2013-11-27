#ifndef __DISANDRIAAPP_DISANDRIA_H
#define __DISANDRIAAPP_DISANDRIA_H

#include <Poco/Util/Application.h>
#include "RenderWindow.h"

class DisandriaApp : public Poco::Util::Application
{
private:
    void initialize(Poco::Util::Application&);
    void reinitialize(Poco::Util::Application&);
    void uninitialize();
    void defineOptions(Poco::Util::OptionSet&);
    int main(const std::vector<std::string>& args);
    const char* name() const;
    void handleVersion(const std::string&, const std::string&);
    void handleHelp(const std::string&, const std::string&);
    void displayHelp();
    /* Members */
    RenderWindow* rwin;
};

#endif // __DISANDRIAAPP_DISANDRIA_H
