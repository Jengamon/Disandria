#include "dfsapi_sf_SoundBuffer.h"
#include <Poco/Foundation.h>
#include <iostream>

void dfsapi_sf_SoundBuffer::init(Falcon::VMachine* vm)
{
    dfsapi_sf_SoundBuffer* self = Falcon::dyncast<dfsapi_sf_SoundBuffer*>(vm->self().asObject());
}

Falcon::CoreObject* dfsapi_sf_SoundBuffer::factory(const Falcon::CoreClass* origin, void* data, bool bDeser)
{
    if(data != 0)
        return new dfsapi_sf_SoundBuffer(origin, reinterpret_cast<sf::SoundBuffer*>(data));
    else
        return new dfsapi_sf_SoundBuffer(origin, new sf::SoundBuffer);
}

dfsapi_sf_SoundBuffer::dfsapi_sf_SoundBuffer(const Falcon::CoreClass* generator, sf::SoundBuffer* _sndbuf) : Falcon::CoreObject(generator), sndbuf(_sndbuf)
{
    poco_assert(_sndbuf != NULL);
}

dfsapi_sf_SoundBuffer::dfsapi_sf_SoundBuffer(const dfsapi_sf_SoundBuffer& other) : Falcon::CoreObject(other), sndbuf(other.sndbuf)
{
    poco_assert(other.sndbuf != NULL);
}

Falcon::CoreObject* dfsapi_sf_SoundBuffer::clone() const
{
    return new dfsapi_sf_SoundBuffer(*this);
}

bool dfsapi_sf_SoundBuffer::setProperty(const Falcon::String& prop, const Falcon::Item& value)
{
	if(prop == "duration" ||
		prop == "channelCount" ||
		prop == "sampleRate")
		throw new Falcon::AccessError(Falcon::ErrorParam(Falcon::e_prop_ro).extra(prop));
    return false;
}

bool dfsapi_sf_SoundBuffer::getProperty(const Falcon::String& key, Falcon::Item& ret) const
{
	if(key == "duration")
		ret = sndbuf->getDuration().asSeconds();
	else if(key == "channelCount")
		ret = (Falcon::int64)sndbuf->getChannelCount();
	else if(key == "sampleRate")
		ret = (Falcon::int64)sndbuf->getSampleRate();
	else if(key == "sampleCount")
		ret = (Falcon::int64)sndbuf->getSampleCount();
	else
		return defaultProperty(key, ret);
	return true;
}

FALCON_FUNC dfsapi_sf_SoundBuffer::loadFromFile(Falcon::VMachine* vm)
{
    dfsapi_sf_SoundBuffer* self = static_cast<dfsapi_sf_SoundBuffer*>(vm->self().asObject());
    Falcon::Item* rpath = vm->param(0);
    if(rpath == NULL || !rpath->isString()) {
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("S"));
    }

    vm->retval(self->sndbuf->loadFromFile(Falcon::AutoCString(rpath->asString()).c_str()));
}
