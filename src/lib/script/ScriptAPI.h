#ifndef SCRIPT_SCRIPTAPI_H
#define SCRIPT_SCRIPTAPI_H

#include <string>

class ScriptAPI
{
	public:
		static double VERSION;
		virtual std::string languageID() = 0;
};

#endif // SCRIPT_SCRIPTAPI_H
