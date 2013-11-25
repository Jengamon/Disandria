#include "FalconCEGUIBinder.h"
#include "../../../../helplib/Log.h"

FalconCEGUIBinder::FalconCEGUIBinder(Falcon::VMachine* vm, std::string name) : cvm(NULL), lck(NULL)
{
    if(vm != NULL) {
        Falcon::Item* func = vm->findGlobalItem(name.c_str());
        if(func != NULL && func->isCallable()) {
            lck = new Falcon::GarbageLock(*func);
            cvm = vm;
        }
    }
}

bool FalconCEGUIBinder::operator()(const CEGUI::EventArgs& args)
{
    if(cvm != NULL) {
        cvm->pushParameter(Falcon::String(" x is awesome! "));
        cvm->callItem(lck->item(), 1);
        if(cvm->regA().isBoolean()) {
            return cvm->regA().asBoolean();
        } else {
            Log::log(PE::Logging::WARNING, "CEGUI bound callable item did not return a boolean. Assuming true...");
            return true;
        }
    }
}

FalconCEGUIBinder::~FalconCEGUIBinder()
{
    cvm = NULL;
    delete lck;
}
