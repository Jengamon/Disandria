#include "dfsapi_DisandriaObjectShare.h"

std::map<std::string, Falcon::GarbageLock*> dfsapi_DisandriaObjectShare::objectHolder;

FALCON_FUNC dfsapi_DisandriaObjectShare::addObject(Falcon::VMachine* vm)
{
    Falcon::Item* name = vm->param(0);
    Falcon::Item* obj = vm->param(1);

    if((name == NULL || !name->isString()) ||
            (obj == NULL || obj->isNil())) {
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("S,X"));
    }

    std::string rname = Falcon::AutoCString(name->asString()).c_str();
    objectHolder[rname] = new Falcon::GarbageLock(*obj);
    vm->retnil();
}

FALCON_FUNC dfsapi_DisandriaObjectShare::getObject(Falcon::VMachine* vm)
{
    Falcon::Item* name = vm->param(0);
    if(name == NULL || !name->isString()) {
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("S"));
    }

    std::string rname = Falcon::AutoCString(name->asString()).c_str();
    if(objectHolder.find(rname) != objectHolder.end()) {
        vm->retval(objectHolder.find(rname)->second->item());
    } else {
        vm->retnil();
    }
}

FALCON_FUNC dfsapi_DisandriaObjectShare::removeObject(Falcon::VMachine* vm)
{
    Falcon::Item* name = vm->param(0);
    if(name == NULL || !name->isString()) {
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("S"));
    }

    std::string rname = Falcon::AutoCString(name->asString()).c_str();
    if(objectHolder.find(rname) != objectHolder.end()) {
        delete objectHolder.find(rname)->second;
        objectHolder.erase(objectHolder.find(rname));
    }
}

FALCON_FUNC dfsapi_DisandriaObjectShare::isObjectAvailable(Falcon::VMachine* vm)
{
    Falcon::Item* name = vm->param(0);
    if(name == NULL || !name->isString()) {
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("S"));
    }

    std::string rname = Falcon::AutoCString(name->asString()).c_str();
    bool isAvailable = objectHolder.find(rname) != objectHolder.end();
    vm->retval(isAvailable);
}