#include "FalconSAPI.h"
#include "../GameManager.h"
#include "falcon/DisandriaFalconSAPI.h"
#include <iostream>

void FalconSAPI::initialize()
{
	Falcon::Engine::Init();
	vm = new Falcon::VMachine();
	modloader = new Falcon::ModuleLoader(GameManager::getGameFolderName().c_str());
	modloader->addFalconPath();
	vm->link(Falcon::core_module_init());
	vm->link(DisandriaFalconSAPI::createBinding());
}

void FalconSAPI::createBindings()
{
}

int FalconSAPI::scriptRequests()
{
	return SubmitType_FILENAME;
}

void FalconSAPI::scriptByFilename(std::string fileName)
{
	Falcon::Runtime rt(modloader, vm);
	try {
		rt.loadFile(fileName.c_str());
		vm->link(&rt);
		vm->launch();
	} catch(Falcon::Error* err) {
		Falcon::AutoCString edesc( err->toString() );
		std::cerr << edesc.c_str() << std::endl;
		err->decref();
		return;
	}
	vm->unlink(&rt);
}

void FalconSAPI::destroyBindings()
{
}

void FalconSAPI::uninitialize()
{
	vm->unlink(Falcon::core_module_init());
	vm->unlink(DisandriaFalconSAPI::createBinding());
	delete modloader;
	vm->finalize();
	vm = NULL;
}
