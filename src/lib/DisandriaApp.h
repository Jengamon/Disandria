#ifndef __DISANDRIAAPP_DISANDRIA_H
#define __DISANDRIAAPP_DISANDRIA_H

#include <Poco/Util/Application.h>

class DisandriaApp : public Poco::Util::Application
{
	void initialize(Poco::Util::Application&);
	void reinitialize(Poco::Util::Application& self);
	void uninitialize();
	void defineOptions(Poco::Util::OptionSet&);
	int main(const std::vector<std::string>& args);
	const char* name();
	void sayVersion(const std::string&, const std::string&);
};

#endif // __DISANDRIAAPP_DISANDRIA_H
