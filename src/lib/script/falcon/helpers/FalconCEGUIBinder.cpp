#include "FalconCEGUIBinder.h"

FalconCEGUIBinder::FalconCEGUIBinder(Falcon::VMachine* vm, std::string name) : cvm(NULL), lck(NULL)
{
    if(vm != NULL) {
        Falcon::Item* func = vm->findGlobalSymbol(name.c_str());
        if(func != NULL && func->isCallable()) {
            lck = new GarbageLock(*func);
            cvm = vm;
        }
    }
}

bool FalconCEGUIBinder::operator()(const CEGUI::EventArgs& args)
{
    if(cvm != NULL) {
    }
}
