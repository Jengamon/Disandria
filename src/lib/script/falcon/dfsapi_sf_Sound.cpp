#include "dfsapi_sf_Sound.h"
#include "dfsapi_sf_SoundBuffer.h"
#include <Poco/Foundation.h>
#include <iostream>
void dfsapi_sf_Sound::init(Falcon::VMachine* vm)
{
    dfsapi_sf_Sound* self = Falcon::dyncast<dfsapi_sf_Sound*>(vm->self().asObject());
    Falcon::Item* rsndbuf = vm->param(0);
    if(rsndbuf != NULL && rsndbuf->isObject())
    {
		self->lck = new Falcon::GarbageLock(*rsndbuf);
		dfsapi_sf_SoundBuffer* sndbuf = Falcon::dyncast<dfsapi_sf_SoundBuffer*>(rsndbuf->asObject());
		self->sound()->setBuffer(*sndbuf->soundbuffer().get());
	}
}

Falcon::CoreObject* dfsapi_sf_Sound::factory(const Falcon::CoreClass* origin, void* data, bool bDeser)
{
    if(data != 0)
        return new dfsapi_sf_Sound(origin, reinterpret_cast<sf::Sound*>(data));
    else
        return new dfsapi_sf_Sound(origin, new sf::Sound);
}

dfsapi_sf_Sound::dfsapi_sf_Sound(const Falcon::CoreClass* generator, sf::Sound* _snd) : Falcon::CoreObject(generator), snd(_snd), lck(NULL) {}

dfsapi_sf_Sound::dfsapi_sf_Sound(const dfsapi_sf_Sound& other) : Falcon::CoreObject(other), snd(other.snd), lck(NULL) {}

dfsapi_sf_Sound::~dfsapi_sf_Sound()
{
	if(lck != NULL)
		delete lck;
}

Falcon::CoreObject* dfsapi_sf_Sound::clone() const
{
    return new dfsapi_sf_Sound(*this);
}

bool dfsapi_sf_Sound::setProperty(const Falcon::String& prop, const Falcon::Item& value)
{
    return false;
}

bool dfsapi_sf_Sound::getProperty(const Falcon::String& key, Falcon::Item& ret) const
{
    return defaultProperty(key, ret);
}

/* Falconizing sf::Sound methods */
FALCON_FUNC dfsapi_sf_Sound::setBuffer(Falcon::VMachine* vm)
{
	dfsapi_sf_Sound* self = static_cast<dfsapi_sf_Sound*>(vm->self().asObject());
	Falcon::Item* rsndbuf = vm->param(0);
	if(rsndbuf == NULL || !rsndbuf->isObject())
	{
		throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("sfSoundBuffer"));
	}
	
	self->lck = new Falcon::GarbageLock(*rsndbuf);
	dfsapi_sf_SoundBuffer* sndbuf = Falcon::dyncast<dfsapi_sf_SoundBuffer*>(rsndbuf->asObject());
	self->snd->setBuffer(*sndbuf->soundbuffer());
	vm->retnil();
}

FALCON_FUNC dfsapi_sf_Sound::getBuffer(Falcon::VMachine* vm)
{
	dfsapi_sf_Sound* self = static_cast<dfsapi_sf_Sound*>(vm->self().asObject());
	const sf::SoundBuffer* sndbuf = self->snd->getBuffer();
	Falcon::Item* sfSoundBufferClassItem = vm->findWKI("sfSoundBuffer");
	Falcon::CoreClass* sfSoundBufferClass = sfSoundBufferClassItem->asClass();
	std::cout << sndbuf << std::endl;
	vm->retval(new dfsapi_sf_SoundBuffer(sfSoundBufferClass, const_cast<sf::SoundBuffer*>(sndbuf)));
}

FALCON_FUNC dfsapi_sf_Sound::play(Falcon::VMachine* vm)
{
    dfsapi_sf_Sound* self = static_cast<dfsapi_sf_Sound*>(vm->self().asObject());
    self->snd->play();
    vm->retnil();
}

FALCON_FUNC dfsapi_sf_Sound::pause(Falcon::VMachine* vm)
{
    dfsapi_sf_Sound* self = static_cast<dfsapi_sf_Sound*>(vm->self().asObject());
    self->snd->pause();
    vm->retnil();
}

FALCON_FUNC dfsapi_sf_Sound::stop(Falcon::VMachine* vm)
{
    dfsapi_sf_Sound* self = static_cast<dfsapi_sf_Sound*>(vm->self().asObject());
    self->snd->stop();
    vm->retnil();
}

FALCON_FUNC dfsapi_sf_Sound::getStatus(Falcon::VMachine* vm)
{
    dfsapi_sf_Sound* self = static_cast<dfsapi_sf_Sound*>(vm->self().asObject());
    vm->retval((Falcon::int64)self->snd->getStatus());
}

FALCON_FUNC dfsapi_sf_Sound::setPlayingOffset(Falcon::VMachine* vm)
{
    dfsapi_sf_Sound* self = static_cast<dfsapi_sf_Sound*>(vm->self().asObject());
    Falcon::Item* playingOffset = vm->param(0);
    double plyOff = 0;
    if(playingOffset == NULL || !playingOffset->isNumeric()) {
        if(playingOffset == NULL || !playingOffset->isInteger())
            throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("Ordinal"));
        else
            plyOff = playingOffset->asInteger();
    } else
        plyOff = playingOffset->asNumeric();

    sf::Time tmOffset = sf::seconds(plyOff);
    self->snd->setPlayingOffset(tmOffset);
    vm->retnil();
}

FALCON_FUNC dfsapi_sf_Sound::getPlayingOffset(Falcon::VMachine* vm)
{
    dfsapi_sf_Sound* self = static_cast<dfsapi_sf_Sound*>(vm->self().asObject());
    vm->retval(self->snd->getPlayingOffset().asSeconds());
}

FALCON_FUNC dfsapi_sf_Sound::setLoop(Falcon::VMachine* vm)
{
    dfsapi_sf_Sound* self = static_cast<dfsapi_sf_Sound*>(vm->self().asObject());
    Falcon::Item* rloop = vm->param(0);
    if(rloop == NULL || !rloop->isBoolean()) {
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("Boolean"));
    }

    bool loop = rloop->asBoolean();
    self->snd->setLoop(loop);
    vm->retnil();
}

FALCON_FUNC dfsapi_sf_Sound::getLoop(Falcon::VMachine* vm)
{
    dfsapi_sf_Sound* self = static_cast<dfsapi_sf_Sound*>(vm->self().asObject());
    vm->retval(self->snd->getLoop());
}

FALCON_FUNC dfsapi_sf_Sound::setPitch(Falcon::VMachine* vm)
{
    dfsapi_sf_Sound* self = static_cast<dfsapi_sf_Sound*>(vm->self().asObject());
    Falcon::Item* rpitch = vm->param(0);
    double pitch = 0;
    if(rpitch == NULL || !rpitch->isNumeric()) {
        if(rpitch == NULL || !rpitch->isInteger())
            throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("Numeric"));
        else
            pitch = rpitch->asInteger();
    } else
        pitch = rpitch->asNumeric();

    self->snd->setPitch(pitch);
    vm->retnil();
}

FALCON_FUNC dfsapi_sf_Sound::getPitch(Falcon::VMachine* vm)
{
    dfsapi_sf_Sound* self = static_cast<dfsapi_sf_Sound*>(vm->self().asObject());
    vm->retval(self->snd->getPitch());
}

FALCON_FUNC dfsapi_sf_Sound::setVolume(Falcon::VMachine* vm)
{
    dfsapi_sf_Sound* self = static_cast<dfsapi_sf_Sound*>(vm->self().asObject());
    Falcon::Item* rvolume = vm->param(0);
    double volume = 0;
    if(rvolume == NULL || !rvolume->isNumeric()) {
        if(rvolume == NULL || !rvolume->isInteger())
            throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("Numeric"));
        else
            volume = rvolume->asInteger();
    } else
        volume = rvolume->asNumeric();

    self->snd->setVolume(volume);
    vm->retnil();
}

FALCON_FUNC dfsapi_sf_Sound::getVolume(Falcon::VMachine* vm)
{
    dfsapi_sf_Sound* self = static_cast<dfsapi_sf_Sound*>(vm->self().asObject());
    vm->retval(self->snd->getVolume());
}
