#include "FalconScriptModule.h"
#include "../GameManager.h"

FalconScriptModule::FalconScriptModule(Falcon::VMachine* vm) : d_ownsVM(vm == NULL), d_vm(vm)
{
    Falcon::Engine::Init();
    if(!d_vm) {
        d_ownsVM = true;
        d_m_load = new Falcon::ModuleLoader(GameManager::getGameFolderName().c_str());
        d_m_load->addFalconPath();
        d_m_load->addDirectoryBack(".");
        d_vm = new Falcon::VMachine;
        d_vm->link(Falcon::core_module_init());
    }
}

FalconScriptModule::~FalconScriptModule()
{
    if(d_vm) {
        if(d_ownsVM) {
            delete d_m_load;
            d_vm->finalize();
        }
        Falcon::Engine::Shutdown();
    }
}

FalconScriptModule& FalconScriptModule::create(Falcon::VMachine* vm)
{
    FalconScriptModule* mod = new FalconScriptModule(vm);
    return *mod;
}

void FalconScriptModule::destroy(FalconScriptModule& mod)
{
    FalconScriptModule* modpointer = &mod;
    delete modpointer;
}

void FalconScriptModule::executeScriptFile(const CEGUI::String& filename, const CEGUI::String& resourceGroup)
{
	Falcon::Runtime* d_rtc = new Falcon::Runtime(d_m_load);
    d_rtc->loadFile((static_cast<CEGUI::DefaultResourceProvider*>(CEGUI::System::getSingleton().getResourceProvider())->getResourceGroupDirectory(resourceGroup) + filename).c_str());
    d_vm->link(d_rtc);
    delete d_rtc;
    d_vm->launch();
}

int FalconScriptModule::executeScriptGlobal(const CEGUI::String& function_name)
{
    Falcon::Item* item = d_vm->getBinding(function_name.c_str());
    if(item != NULL && item->isMethod()) {
        item->asMethodFunc()->readyFrame(d_vm, 0);
        if(!d_vm->regA().isInteger()) {
            CEGUI_THROW(CEGUI::ScriptException("Unable to get Falcon global: '" + function_name + "' return value as it's not a number"));
            return -1;
        }
    } else {
        CEGUI_THROW(CEGUI::ScriptException("Unable to get Falcon global: '" + function_name + "' as name does not represent Falcon function"));
    }
    return d_vm->regA().asInteger();
}

bool FalconScriptModule::executeScriptedEventHandler(const CEGUI::String& handler_name, const CEGUI::EventArgs& e)
{
    return true;
}

void FalconScriptModule::executeString(const CEGUI::String& str)
{
}

CEGUI::Event::Connection FalconScriptModule::subscribeEvent(CEGUI::EventSet* target, const CEGUI::String& name, const CEGUI::String& subscriber_name)
{
    return *new CEGUI::Event::Connection(NULL);
}

CEGUI::Event::Connection FalconScriptModule::subscribeEvent(CEGUI::EventSet* target, const CEGUI::String& name, const CEGUI::Event::Group group, const CEGUI::String& subscriber_name)
{
    return *new CEGUI::Event::Connection(NULL);
}

void FalconScriptModule::createBindings()
{
}

void FalconScriptModule::destroyBindings()
{
}
