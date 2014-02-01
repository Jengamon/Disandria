#include "dfsapi_thor_Action.h"
#include <Poco/Foundation.h>
#include <SFML/Window.hpp>
#include <iostream>

void dfsapi_thor_Action::init(Falcon::VMachine* vm)
{
    dfsapi_thor_Action* self = Falcon::dyncast<dfsapi_thor_Action*>(vm->self().asObject());
    Falcon::Item* keyobut = vm->param(0);
    Falcon::Item* act = vm->param(1);
    if(keyobut == NULL || !keyobut->isOrdinal()) {
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("I, [I]"));
    }

    Falcon::int64 kob = keyobut->forceInteger();
    if(kob - (Falcon::int64)sf::Keyboard::KeyCount > 0) {
        sf::Mouse::Button but = sf::Mouse::Button(kob - ((Falcon::int64)sf::Keyboard::KeyCount + 1));
        if(act != NULL)
            self->action().reset(new thor::Action(but, (thor::Action::ActionType)act->forceInteger()));
        else
            self->action().reset(new thor::Action(but));
    } else {
        sf::Keyboard::Key key = (sf::Keyboard::Key)kob;
        if(act != NULL)
            self->action().reset(new thor::Action(key, (thor::Action::ActionType)act->forceInteger()));
        else
            self->action().reset(new thor::Action(key));
    }
}

Falcon::CoreObject* dfsapi_thor_Action::factory(const Falcon::CoreClass* origin, void* data, bool deser)
{
    if(data != 0)
        return new dfsapi_thor_Action(origin, reinterpret_cast<thor::Action*>(data));
    else
        return new dfsapi_thor_Action(origin, new thor::Action(sf::Keyboard::Unknown));
}

dfsapi_thor_Action::dfsapi_thor_Action(const Falcon::CoreClass* gen, thor::Action* _act) : Falcon::CoreObject(gen), act(_act)
{
    poco_assert(_act != NULL);
}

dfsapi_thor_Action::dfsapi_thor_Action(const Falcon::CoreClass* gen, thor::Action _act) : Falcon::CoreObject(gen), act(new thor::Action(_act)) {}

dfsapi_thor_Action::dfsapi_thor_Action(const dfsapi_thor_Action& other) : Falcon::CoreObject(other), act(other.act) {}

Falcon::CoreObject* dfsapi_thor_Action::clone() const
{
    return new dfsapi_thor_Action(*this);
}

bool dfsapi_thor_Action::setProperty(const Falcon::String& prop, const Falcon::Item& val)
{
    return false;
}

bool dfsapi_thor_Action::getProperty(const Falcon::String& prop, Falcon::Item& ret) const
{
    return defaultProperty(prop, ret);
}

FALCON_FUNC dfsapi_thor_Action::combineAnd(Falcon::VMachine* vm)
{
    dfsapi_thor_Action* self = Falcon::dyncast<dfsapi_thor_Action*>(vm->self().asObject());
    Falcon::Item* toBeAnd = vm->param(0);
    if(toBeAnd == NULL || !toBeAnd->isObject()) {
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("thorAction"));
    }

    dfsapi_thor_Action* other = Falcon::dyncast<dfsapi_thor_Action*>(toBeAnd->asObject());
    Falcon::Item* dfsata_cls = vm->findWKI("thorAction");
    vm->retval(new dfsapi_thor_Action(dfsata_cls->asClass(), *self->action() && *other->action()));
}

FALCON_FUNC dfsapi_thor_Action::combineOr(Falcon::VMachine* vm)
{
    dfsapi_thor_Action* self = Falcon::dyncast<dfsapi_thor_Action*>(vm->self().asObject());
    Falcon::Item* toBeAnd = vm->param(0);
    if(toBeAnd == NULL || !toBeAnd->isObject()) {
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("thorAction"));
    }

    dfsapi_thor_Action* other = Falcon::dyncast<dfsapi_thor_Action*>(toBeAnd->asObject());
    Falcon::Item* dfsata_cls = vm->findWKI("thorAction");
    vm->retval(new dfsapi_thor_Action(dfsata_cls->asClass(), *self->action() || *other->action()));
}
