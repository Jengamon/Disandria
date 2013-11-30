#ifndef __DISANDRIA_DISANDRIAFALCONSAPI_H
#define __DISANDRIA_DISANDRIAFALCONSAPI_H

#include <falcon/engine.h>

class DisandriaFalconSAPI
{
	public:
		static Falcon::Module* createBinding();
	private:
		static void addConstants(Falcon::Module*);
		static void addMethods(Falcon::Module*);
		static void addClasses(Falcon::Module*);
		static void addSingletons(Falcon::Module*);
		static Falcon::Module* module;
};

#endif // __DISANDRIA_DISANDRIAFALCONSAPI_H
