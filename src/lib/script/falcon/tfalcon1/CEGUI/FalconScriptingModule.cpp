#include "FalconScriptingModule.h"
#include "FalconInterpreter.h"
#include "../../GameManager.h"
#include "../falcon/DisandriaFalconSAPI.h"
#include "CEGUIFalconBinding.h"
#include <iostream>

FalconScriptingModule* FalconScriptingModule::create(Falcon::VMachine* vm)
{
    return new FalconScriptingModule(vm);
}

FalconScriptingModule::FalconScriptingModule(Falcon::VMachine* vm) : d_vm(vm), d_ownsVM(vm == 0)
{
    const CEGUI::String& dir = static_cast<CEGUI::DefaultResourceProvider*>(CEGUI::System::getSingleton().getResourceProvider())->getResourceGroupDirectory(this->getDefaultResourceGroup());
    Falcon::Engine::Init();
    d_ml = new Falcon::ModuleLoader(GameManager::getGameFolderName().c_str());
    d_ml->addFalconPath();
    d_ml->addDirectoryBack(dir.c_str());
    if(!d_vm) {
        d_ownsVM = true;
        d_vm = new Falcon::VMachine;
        d_vm->link(Falcon::core_module_init());
        d_vm->link(DisandriaFalconSAPI::createBinding());
        d_vm->link(CEGUIFalconBinding::createBinding());
    }
    setModuleIdentifierString();
}

CEGUI::Event::Connection FalconScriptingModule::subscribeEvent(CEGUI::EventSet* target, const CEGUI::String& name, const CEGUI::String& subscriber_name)
{
    FalconInterpreter interp(d_vm, subscriber_name.c_str());
    return target->subscribeEvent(name, CEGUI::Event::Subscriber(interp));
}

CEGUI::Event::Connection FalconScriptingModule::subscribeEvent(CEGUI::EventSet* target, const CEGUI::String& name, CEGUI::Event::Group group, const CEGUI::String& subscriber_name)
{
    FalconInterpreter interp(d_vm, subscriber_name.c_str());
    return target->subscribeEvent(name, group, CEGUI::Event::Subscriber(interp));
}

void FalconScriptingModule::executeScriptFile(const CEGUI::String& filename, const CEGUI::String& resourceGroup)
{
    try {
        Falcon::Runtime rt(d_ml);
        rt.loadFile(filename.c_str());
        d_vm->link(&rt);
    } catch(Falcon::Error* err) {
        Falcon::AutoCString edesc(err->toString());
        std::cerr << edesc.c_str() << std::endl;
        err->decref();
        return;
    }
}

int FalconScriptingModule::executeScriptGlobal(const CEGUI::String& function_name)
{
    Falcon::Item* func = d_vm->findGlobalItem(Falcon::String(function_name.c_str()));
    if(func != NULL && func->isCallable()) {
        d_vm->callItem(*func, 0);
        d_vm->reset();
        Falcon::Item& ret = d_vm->regA();
        return ret.forceInteger();
    }
    return 0;
}

void FalconScriptingModule::executeString(const CEGUI::String& str)
{
    /* Falcon::ModuleLoader mod(*d_ml);
     Falcon::Module* modl = mod.loadSource(str.c_str());
     Falcon::Runtime rt(&mod);
     Falcon::VMachine* vm = new Falcon::VMachine;
     vm->link(&rt);
     vm->launch();
     vm->unlink(&rt);
     vm->finalize();*/
}

bool FalconScriptingModule::executeScriptedEventHandler(const CEGUI::String& handler_name, const CEGUI::EventArgs& e)
{
    Falcon::Item* func = d_vm->findGlobalItem(Falcon::String(handler_name.c_str()));
    if(func != NULL && func->isCallable()) {
        d_vm->pushParam(3);
        d_vm->callItem(*func, 1);
        d_vm->reset();
        Falcon::Item& ret = d_vm->regA();
        return ret.isBoolean() ? ret.asBoolean() : true;
    }
    return false;
}

void FalconScriptingModule::setModuleIdentifierString()
{
    d_identifierString = "DFalcon - Falcon CEGUI binding for Disandria";
}
