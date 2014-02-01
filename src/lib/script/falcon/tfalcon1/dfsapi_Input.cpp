#include "dfsapi_Input.h"
#include "dfsapi_thor_Action.h"
#include "DisandriaFalconSAPI.h"
#include <Poco/Foundation.h>
#include <iostream>
#include <memory>

FALCON_FUNC dfsapi_Input_addAction(Falcon::VMachine* vm)
{
    Falcon::Item* name = vm->param(0);
    Falcon::Item* thorAction = vm->param(1);
    if((name == NULL || !name->isString()) ||
            (thorAction == NULL || !thorAction->isObject())) {
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("S, thorAction"));
    }

    dfsapi_thor_Action* act = Falcon::dyncast<dfsapi_thor_Action*>(thorAction->asObject());
    RenderWindowManager::getRenderWindow("ROOT")->addAction(
        Falcon::AutoCString(*name).c_str(),
        *act->action());
}

FALCON_FUNC dfsapi_Input_addCallback(Falcon::VMachine* vm)
{
    Falcon::Item* name = vm->param(0);
    Falcon::Item* function = vm->param(1);
    if((name == NULL || !name->isString()) ||
            (function == NULL || !function->isCallable())) {
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("S, C"));
    }

    RenderWindowManager::getRenderWindow("ROOT")->addCallback(
        Falcon::AutoCString(*name).c_str(),
    [&](thor::ActionContext<std::string> context) -> void {
        vm->pushParam(Falcon::String("To be pushed!"));
        vm->callItem(*function, 1);
        vm->reset();
    }
    );
}

void runFalconFunctionAsAction(Falcon::VMachine* vm, Falcon::GarbageLock* lck)
{
    //Falcon::VMachine* vmp = dynamic_cast<FalconSAPI*>(ScriptAPILibrary::instance->getAPI("Falcon"))->getVM();
    std::cout << *reinterpret_cast<std::string*>(vm->userData()) << std::endl;
    vm->link(Falcon::core_module_init());
    try {
        //vm->prepareFrame(lck->item()->asFunction(), 1);
        vm->pushParam(Falcon::String("To be pushed!"));
        //vm->callFrame(lck->item(), 1);
        //vm->run();
        vm->callItem(lck->item(), 1);
        //vm->functionalEval(lck->item(), 1);
    } catch(Falcon::Error* err) {
        Falcon::AutoCString edesc(err->toString());
        std::cerr << edesc.c_str() << std::endl;
        err->decref();
        return;
    }
    vm->reset();
}

FALCON_FUNC dfsapi_Input_addActionCallback(Falcon::VMachine* vm)
{
    Falcon::Item* name = vm->param(0);
    Falcon::Item* thorAction = vm->param(1);
    Falcon::Item* function = vm->param(2);
    if((name == NULL || !name->isString()) ||
            (thorAction == NULL || !thorAction->isObject()) ||
            (function == NULL || !function->isCallable())) {
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("S, thorAction, C"));
    }

    Falcon::GarbageLock* lck = new Falcon::GarbageLock(*function);
    //vmp = vm;
    dfsapi_thor_Action* act = Falcon::dyncast<dfsapi_thor_Action*>(thorAction->asObject());
    RenderWindowManager::getRenderWindow("ROOT")->addActionCallback(
        Falcon::AutoCString(*name).c_str(),
        *act->actionnref(),
        std::bind(&runFalconFunctionAsAction, vm, lck)
    );
}

FALCON_FUNC dfsapi_Input_removeCallback(Falcon::VMachine*)
{
}

FALCON_FUNC dfsapi_Input_clearCallbacks(Falcon::VMachine*)
{
}
