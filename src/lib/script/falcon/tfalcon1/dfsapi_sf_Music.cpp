#include "dfsapi_sf_Music.h"
#include <Poco/Foundation.h>
#include <iostream>

void dfsapi_sf_Music::init(Falcon::VMachine* vm)
{
    dfsapi_sf_Music* self = Falcon::dyncast<dfsapi_sf_Music*>(vm->self().asObject());
    Falcon::Item* item = vm->param(0);
    if(item != NULL && item->isObject()) {
        dfsapi_sf_Music* other = Falcon::dyncast<dfsapi_sf_Music*>(item->asObject());
        self->msc = other->msc;
    }
}

Falcon::CoreObject* dfsapi_sf_Music::factory(const Falcon::CoreClass* origin, void* data, bool bDeser)
{
    if(data != 0)
        return new dfsapi_sf_Music(origin, reinterpret_cast<sf::Music*>(data));
    else
        return new dfsapi_sf_Music(origin, new sf::Music);
}

dfsapi_sf_Music::dfsapi_sf_Music(const Falcon::CoreClass* generator, sf::Music* _msc) : Falcon::CoreObject(generator), msc(_msc)
{
    poco_assert(_msc != NULL);
}

dfsapi_sf_Music::dfsapi_sf_Music(const Falcon::CoreClass* gen, std::shared_ptr<sf::Music> _msc) : Falcon::CoreObject(gen)
{
    msc = _msc;
}

dfsapi_sf_Music::dfsapi_sf_Music(const dfsapi_sf_Music& other) : Falcon::CoreObject(other), msc(other.msc)
{
    poco_assert(other.msc != NULL);
}

Falcon::CoreObject* dfsapi_sf_Music::clone() const
{
    return new dfsapi_sf_Music(*this);
}

bool dfsapi_sf_Music::setProperty(const Falcon::String& prop, const Falcon::Item& value)
{
    return false;
}

bool dfsapi_sf_Music::getProperty(const Falcon::String& key, Falcon::Item& ret) const
{
    return defaultProperty(key, ret);
}

/* Falconizing sf::Music methods */
FALCON_FUNC dfsapi_sf_Music::openFromFile(Falcon::VMachine* vm)
{
    dfsapi_sf_Music* self = static_cast<dfsapi_sf_Music*>(vm->self().asObject());
    Falcon::Item* fileName = vm->param(0);
    if(fileName == NULL || !fileName->isString()) {
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("S"));
    }

    vm->retval(self->msc->openFromFile(Falcon::AutoCString(*fileName->asString()).c_str()));
}

FALCON_FUNC dfsapi_sf_Music::getDuration(Falcon::VMachine* vm)
{
    dfsapi_sf_Music* self = static_cast<dfsapi_sf_Music*>(vm->self().asObject());
    vm->retval(self->msc->getDuration().asSeconds());
}

FALCON_FUNC dfsapi_sf_Music::play(Falcon::VMachine* vm)
{
    dfsapi_sf_Music* self = static_cast<dfsapi_sf_Music*>(vm->self().asObject());
    self->msc->play();
    vm->retnil();
}

FALCON_FUNC dfsapi_sf_Music::pause(Falcon::VMachine* vm)
{
    dfsapi_sf_Music* self = static_cast<dfsapi_sf_Music*>(vm->self().asObject());
    self->msc->pause();
    vm->retnil();
}

FALCON_FUNC dfsapi_sf_Music::stop(Falcon::VMachine* vm)
{
    dfsapi_sf_Music* self = static_cast<dfsapi_sf_Music*>(vm->self().asObject());
    self->msc->stop();
    vm->retnil();
}

FALCON_FUNC dfsapi_sf_Music::getChannelCount(Falcon::VMachine* vm)
{
    dfsapi_sf_Music* self = static_cast<dfsapi_sf_Music*>(vm->self().asObject());
    vm->retval((Falcon::int64)self->msc->getChannelCount());
}

FALCON_FUNC dfsapi_sf_Music::getSampleRate(Falcon::VMachine* vm)
{
    dfsapi_sf_Music* self = static_cast<dfsapi_sf_Music*>(vm->self().asObject());
    vm->retval((Falcon::int64)self->msc->getSampleRate());
}

FALCON_FUNC dfsapi_sf_Music::getStatus(Falcon::VMachine* vm)
{
    dfsapi_sf_Music* self = static_cast<dfsapi_sf_Music*>(vm->self().asObject());
    vm->retval((Falcon::int64)self->msc->getStatus());
}

FALCON_FUNC dfsapi_sf_Music::setPlayingOffset(Falcon::VMachine* vm)
{
    dfsapi_sf_Music* self = static_cast<dfsapi_sf_Music*>(vm->self().asObject());
    Falcon::Item* playingOffset = vm->param(0);
    double plyOff = 0;
    if(playingOffset == NULL || !playingOffset->isOrdinal())
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("N"));
    else
        plyOff = playingOffset->forceNumeric();

    sf::Time tmOffset = sf::seconds(plyOff);
    self->msc->setPlayingOffset(tmOffset);
    vm->retnil();
}

FALCON_FUNC dfsapi_sf_Music::getPlayingOffset(Falcon::VMachine* vm)
{
    dfsapi_sf_Music* self = static_cast<dfsapi_sf_Music*>(vm->self().asObject());
    vm->retval(self->msc->getPlayingOffset().asSeconds());
}

FALCON_FUNC dfsapi_sf_Music::setLoop(Falcon::VMachine* vm)
{
    dfsapi_sf_Music* self = static_cast<dfsapi_sf_Music*>(vm->self().asObject());
    Falcon::Item* rloop = vm->param(0);
    if(rloop == NULL || !rloop->isBoolean()) {
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("B"));
    }

    bool loop = rloop->asBoolean();
    self->msc->setLoop(loop);
    vm->retnil();
}

FALCON_FUNC dfsapi_sf_Music::getLoop(Falcon::VMachine* vm)
{
    dfsapi_sf_Music* self = static_cast<dfsapi_sf_Music*>(vm->self().asObject());
    vm->retval(self->msc->getLoop());
}

FALCON_FUNC dfsapi_sf_Music::setPitch(Falcon::VMachine* vm)
{
    dfsapi_sf_Music* self = static_cast<dfsapi_sf_Music*>(vm->self().asObject());
    Falcon::Item* rpitch = vm->param(0);
    double pitch = 0;
    if(rpitch == NULL || !rpitch->isOrdinal())
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("N"));
    else
        pitch = rpitch->forceNumeric();

    self->msc->setPitch(pitch);
    vm->retnil();
}

FALCON_FUNC dfsapi_sf_Music::getPitch(Falcon::VMachine* vm)
{
    dfsapi_sf_Music* self = static_cast<dfsapi_sf_Music*>(vm->self().asObject());
    vm->retval(self->msc->getPitch());
}

FALCON_FUNC dfsapi_sf_Music::setVolume(Falcon::VMachine* vm)
{
    dfsapi_sf_Music* self = static_cast<dfsapi_sf_Music*>(vm->self().asObject());
    Falcon::Item* rvolume = vm->param(0);
    double volume = 0;
    if(rvolume == NULL || !rvolume->isOrdinal())
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("N"));
    else
        volume = rvolume->forceNumeric();

    self->msc->setVolume(volume);
    vm->retnil();
}

FALCON_FUNC dfsapi_sf_Music::getVolume(Falcon::VMachine* vm)
{
    dfsapi_sf_Music* self = static_cast<dfsapi_sf_Music*>(vm->self().asObject());
    vm->retval(self->msc->getVolume());
}
