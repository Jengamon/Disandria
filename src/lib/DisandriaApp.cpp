#include "DisandriaApp.h"
using namespace Poco::Util;

void DisandriaApp::initialize(Application& self)
{
	loadConfiguration();
	Application::initialize(self);
}

void DisandriaApp::reinitialize(Application& self)
{
	
}

const char* DisandriaApp::name()
{
	return "Disandria";
}

void DisandriaApp::uninitialize()
{
}

void DisandriaApp::defineOptions(OptionSet& opst)
{
	Option version("version", "v", "Display current Disandria version", false);
	version.callback(OptionCallback<DisandriaApp>(this, &DisandriaApp::sayVersion));
	opst.addOption(version);
}

int DisandriaApp::main(const std::vector<std::string>& args)
{
}

void DisandriaApp::sayVersion(const std::string& name, const std::string& value)
{
	this->logger().notice("Disandria v.0.1");
	stopOptionProcessing();
}
