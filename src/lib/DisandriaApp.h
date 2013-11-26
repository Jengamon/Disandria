#ifndef __DISANDRIAAPP_DISANDRIA_H
#define __DISANDRIAAPP_DISANDRIA_H

#include <Poco/Util/Application.h>

class DisandriaApp : public Poco::Util::Application
{
	void initialize(Poco::Util::Application&);
	void reinitialize();
	void uninitialize();
	void defineOptions(Poco::Util::OptionSet&);
	int main(const std::vector<std::string>& args);
};

#endif // __DISANDRIAAPP_DISANDRIA_H
