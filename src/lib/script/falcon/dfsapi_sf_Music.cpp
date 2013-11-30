#include "dfsapi_sf_Music.h"
#include <Poco/Foundation.h>

void dfsapi_sf_Music::init(Falcon::VMachine* vm)
{
	dfsapi_sf_Music* self = Falcon::dyncast<dfsapi_sf_Music*>(vm->self().asObject());
	Falcon::Item* musicPointer = vm->param(0);
	if(musicPointer == NULL)
	{
		sf::Music* msc = self->music();
		msc = new sf::Music;
		return;
	}
	
	sf::Music* msc = self->music();
	msc = reinterpret_cast<sf::Music*>(musicPointer->asInteger());
	poco_assert(msc != NULL);
}

Falcon::CoreObject* dfsapi_sf_Music::factory(const Falcon::CoreClass* origin, void* data, bool bDeser)
{
	if (data != 0)
		return new dfsapi_sf_Music(origin, reinterpret_cast<sf::Music*>(data), false);
	else
		return new dfsapi_sf_Music(origin, new sf::Music, true);
}

dfsapi_sf_Music::dfsapi_sf_Music(const Falcon::CoreClass* generator, sf::Music* _msc, bool ctrm) : Falcon::CoreObject(generator), msc(_msc), controlMusic(ctrm)
{
	poco_assert(_msc != NULL);
}

Falcon::CoreObject* dfsapi_sf_Music::clone() const
{
	return NULL;
}
		
bool dfsapi_sf_Music::setProperty(const Falcon::String& prop, const Falcon::Item& value )
{
	return false;
}

bool dfsapi_sf_Music::getProperty(const Falcon::String& key, Falcon::Item& ret) const
{
	return defaultProperty(key, ret);
}

dfsapi_sf_Music::~dfsapi_sf_Music()
{
	if(controlMusic)
		delete msc;
}

/* Falconizing sf::Music methods */
FALCON_FUNC dfsapi_sf_Music::openFromFile(Falcon::VMachine* vm)
{
	dfsapi_sf_Music* self = static_cast<dfsapi_sf_Music*>(vm->self().asObject());
	Falcon::Item* fileName = vm->param(0);
	if(fileName == NULL || !fileName->isString())
	{
		throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("String"));
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

FALCON_FUNC dfsapi_sf_Music::getStatus(Falcon::VMachine* vm)
{
	dfsapi_sf_Music* self = static_cast<dfsapi_sf_Music*>(vm->self().asObject());
	vm->retval((Falcon::int64)self->msc->getStatus());
}

FALCON_FUNC dfsapi_sf_Music::setPlayingOffset(Falcon::VMachine* vm)
{
	dfsapi_sf_Music* self = static_cast<dfsapi_sf_Music*>(vm->self().asObject());
	Falcon::Item* playingOffset = vm->param(0);
	if(playingOffset == NULL || !playingOffset->isOrdinal())
	{
		throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("Ordinal"));
	}
	
	double plyOff = playingOffset->asNumeric();
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
	if(rloop == NULL || !rloop->isBoolean())
	{
		throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("Boolean"));
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
