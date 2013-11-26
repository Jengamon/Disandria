#include "DisandriaApp.h"
using namespace Poco::Util;

void DisandriaApp::initialize(Application& self)
{
	loadConfiguration();
	Application::initialize(self);
}

void DisandriaApp::reinitialize()
{
}

void DisandriaApp::uninitialize()
{
}

void DisandriaApp::defineOptions(OptionSet&)
{
}

int DisandriaApp::main(const std::vector<std::string>& args)
{
}
