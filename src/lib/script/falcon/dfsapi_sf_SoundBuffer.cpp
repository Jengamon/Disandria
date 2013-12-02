#include "dfsapi_sf_SoundBuffer.h"
#include <Poco/Foundation.h>

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
    return false;
}

bool dfsapi_sf_SoundBuffer::getProperty(const Falcon::String& key, Falcon::Item& ret) const
{
    return defaultProperty(key, ret);
}

FALCON_FUNC dfsapi_sf_SoundBuffer::loadFromFile(Falcon::VMachine* vm)
{
	dfsapi_sf_SoundBuffer* self = static_cast<dfsapi_sf_SoundBuffer*>(vm->self().asObject());
	Falcon::Item* rpath = vm->param(0);
	if(rpath == NULL || !rpath->isString())
	{
		throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("String"));
	}
	
	vm->retval(self->sndbuf->loadFromFile(Falcon::AutoCString(rpath->asString()).c_str()));
}

FALCON_FUNC dfsapi_sf_SoundBuffer::getDuration(Falcon::VMachine* vm)
{
	dfsapi_sf_SoundBuffer* self = static_cast<dfsapi_sf_SoundBuffer*>(vm->self().asObject());
	vm->retval(self->sndbuf->getDuration().asSeconds());
}

FALCON_FUNC dfsapi_sf_SoundBuffer::getChannelCount(Falcon::VMachine* vm)
{
	dfsapi_sf_SoundBuffer* self = static_cast<dfsapi_sf_SoundBuffer*>(vm->self().asObject());
	vm->retval((Falcon::int64)self->sndbuf->getChannelCount());
}

FALCON_FUNC dfsapi_sf_SoundBuffer::getSampleRate(Falcon::VMachine* vm)
{
	dfsapi_sf_SoundBuffer* self = static_cast<dfsapi_sf_SoundBuffer*>(vm->self().asObject());
	vm->retval((Falcon::int64)self->sndbuf->getSampleRate());
}
