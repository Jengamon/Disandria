#ifndef SCRIPT_FALCONSAPI_H
#define SCRIPT_FALCONSAPI_H

#include "ScriptAPI.h"
#include "falcon/fstringh.h"
#include <falcon/engine.h>

class FalconSAPI : public ScriptAPI
{
	public:
		std::string languageID() { return "FALCON"; }
		FalconSAPI();
		virtual ~FalconSAPI();
		void quickInitialize(std::string);
		void loadFile(std::string);
		void addModulePath(std::string);
		void createVM();
		void loadCoreModule();
		void loadExternalModule(Falcon::Module*);
		void linkRuntime();
		void launch(std::string = "~");
		void createRuntime();
		void addPath(std::string);
	private:
		Falcon::Runtime* runtime;
		Falcon::VMachine* vm;
		Falcon::ModuleLoader* m_loader;
};

Falcon::Module* createAppModule();

#endif // SCRIPT_FALCONSAPI_H
