#ifndef __DISANDRIA_FALCONINTERPRETER_H
#define __DISANDRIA_FALCONINTERPRETER_H

#include <memory>
#include <falcon/engine.h>
#include <CEGUI/CEGUI.h>

/**
 * Falcon CEGUI Event Interpreter
 */
class FalconInterpreter
{
public:
    FalconInterpreter(Falcon::VMachine* pvm, std::string name) : vm(pvm), i_name(name) {
        Falcon::Item* func = vm->findGlobalItem(Falcon::String(i_name.c_str()));
        if(func != NULL && func->isCallable()) {
            ffunc = func;
            //lck.reset(new Falcon::GarbageLock(*func)); <--- May leave commented, as seems not to be required
        } else {
            ffunc = NULL;
        }
    }
    bool operator()(const CEGUI::EventArgs&) const;
private:
    std::string i_name;
    Falcon::VMachine* vm;
    Falcon::Item* ffunc;
    // std::shared_ptr<Falcon::GarbageLock> lck;
};

#endif // __DISANDRIA_FALCONINTERPRETER_H
