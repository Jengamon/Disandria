#include "DisandriaFalconSAPI.h"

/* Bindings to Disandria C++ classes (or C++ functions) */
#include "dfsapi_GameManager.h"
#include "dfsapi_RenderWindow.h"
#include "dfsapi_functions.h"
#include "dfsapi_DisandriaObjectShare.h"

/* Bindings to SFML C++ classes (underlying library of Disandria) */
#include "dfsapi_sf_Music.h"
#include "dfsapi_sf_Sound.h"
#include "dfsapi_sf_SoundBuffer.h"
#include <SFML/Audio.hpp>

Falcon::Module* DisandriaFalconSAPI::module = NULL;

Falcon::Module* DisandriaFalconSAPI::createBinding()
{
    if(module == NULL) {
        module = new Falcon::Module();
        module->name("DisandriaFalcon");
        addConstants(module);
        addMethods(module);
        addClasses(module);
        addSingletons(module);
    }
    return module;
}

void DisandriaFalconSAPI::addConstants(Falcon::Module* mod)
{
    /* sf::SoundSource::Status */
    mod->addConstant("sfSoundSourceStatusStopped", (Falcon::int64)sf::SoundSource::Stopped);
    mod->addConstant("sfSoundSourceStatusPlaying", (Falcon::int64)sf::SoundSource::Playing);
    mod->addConstant("sfSoundSourceStatusPaused", (Falcon::int64)sf::SoundSource::Paused);
}

void DisandriaFalconSAPI::addMethods(Falcon::Module* mod)
{
	mod->addExtFunc("exitDisandria", &closeSystem);
}

void DisandriaFalconSAPI::addClasses(Falcon::Module* mod)
{
    /* sf::Music */
    Falcon::Symbol* sfMusic = mod->addClass("sfMusic", &dfsapi_sf_Music::init);
    sfMusic->setWKS(true);
    sfMusic->getClassDef()->factory(&dfsapi_sf_Music::factory);
    mod->addClassMethod(sfMusic, "openFromFile", &dfsapi_sf_Music::openFromFile);
    mod->addClassMethod(sfMusic, "getDuration", &dfsapi_sf_Music::getDuration);
    mod->addClassMethod(sfMusic, "play", &dfsapi_sf_Music::play);
    mod->addClassMethod(sfMusic, "pause", &dfsapi_sf_Music::pause);
    mod->addClassMethod(sfMusic, "stop", &dfsapi_sf_Music::stop);
    mod->addClassMethod(sfMusic, "getChannelCount", &dfsapi_sf_Music::getChannelCount);
    mod->addClassMethod(sfMusic, "getSampleRate", &dfsapi_sf_Music::getSampleRate);
    mod->addClassMethod(sfMusic, "getStatus", &dfsapi_sf_Music::getStatus);
    mod->addClassMethod(sfMusic, "getPlayingOffset", &dfsapi_sf_Music::getPlayingOffset);
    mod->addClassMethod(sfMusic, "setPlayingOffset", &dfsapi_sf_Music::setPlayingOffset);
    mod->addClassMethod(sfMusic, "getLoop", &dfsapi_sf_Music::getLoop);
    mod->addClassMethod(sfMusic, "setLoop", &dfsapi_sf_Music::setLoop);
    mod->addClassMethod(sfMusic, "getPitch", &dfsapi_sf_Music::getPitch);
    mod->addClassMethod(sfMusic, "setPitch", &dfsapi_sf_Music::setPitch);
    mod->addClassMethod(sfMusic, "getVolume", &dfsapi_sf_Music::getVolume);
    mod->addClassMethod(sfMusic, "setVolume", &dfsapi_sf_Music::setVolume);

    /* sf::SoundBuffer */
    Falcon::Symbol* sfSoundBuffer = mod->addClass("sfSoundBuffer", &dfsapi_sf_SoundBuffer::init);
    sfSoundBuffer->setWKS(true);
    sfSoundBuffer->getClassDef()->factory(&dfsapi_sf_SoundBuffer::factory);
    mod->addClassMethod(sfSoundBuffer, "loadFromFile", &dfsapi_sf_SoundBuffer::loadFromFile);

    /* sf::Sound */
    Falcon::Symbol* sfSound = mod->addClass("sfSound", &dfsapi_sf_Sound::init)->addParam("soundBuffer");
    sfSound->setWKS(true);
    sfSound->getClassDef()->factory(&dfsapi_sf_Sound::factory);
    mod->addClassMethod(sfSound, "play", &dfsapi_sf_Sound::play);
    mod->addClassMethod(sfSound, "getBuffer", &dfsapi_sf_Sound::getBuffer);
    mod->addClassMethod(sfSound, "setBuffer", &dfsapi_sf_Sound::setBuffer);
    mod->addClassMethod(sfSound, "pause", &dfsapi_sf_Sound::pause);
    mod->addClassMethod(sfSound, "stop", &dfsapi_sf_Sound::stop);
    mod->addClassMethod(sfSound, "getStatus", &dfsapi_sf_Sound::getStatus);
    mod->addClassMethod(sfSound, "getPlayingOffset", &dfsapi_sf_Sound::getPlayingOffset);
    mod->addClassMethod(sfSound, "setPlayingOffset", &dfsapi_sf_Sound::setPlayingOffset);
    mod->addClassMethod(sfSound, "getLoop", &dfsapi_sf_Sound::getLoop);
    mod->addClassMethod(sfSound, "setLoop", &dfsapi_sf_Sound::setLoop);
    mod->addClassMethod(sfSound, "getPitch", &dfsapi_sf_Sound::getPitch);
    mod->addClassMethod(sfSound, "setPitch", &dfsapi_sf_Sound::setPitch);
    mod->addClassMethod(sfSound, "getVolume", &dfsapi_sf_Sound::getVolume);
    mod->addClassMethod(sfSound, "setVolume", &dfsapi_sf_Sound::setVolume);
}

void DisandriaFalconSAPI::addSingletons(Falcon::Module* mod)
{
    /* GameManager */
    Falcon::Symbol* gameManagerSingleton = mod->addSingleton("GameManager");
    Falcon::Symbol* gameManagerClass = gameManagerSingleton->getInstance();
    mod->addClassMethod(gameManagerClass, "getGameFolderName", &dfsapi_GameManager_getGameFolderName);
    mod->addClassMethod(gameManagerClass, "getEngineVersion", &dfsapi_GameManager_getEngineVersion);
    
    /* DisandriaObjectShare */
    Falcon::Symbol* disandriaObjectShareSingleton = mod->addSingleton("DisandriaObjectShare");
    Falcon::Symbol* disandriaObjectShareClass = disandriaObjectShareSingleton->getInstance();
    mod->addClassMethod(disandriaObjectShareClass, "addObject", &dfsapi_DisandriaObjectShare::addObject);
    mod->addClassMethod(disandriaObjectShareClass, "getObject", &dfsapi_DisandriaObjectShare::getObject);
    mod->addClassMethod(disandriaObjectShareClass, "removeObject", &dfsapi_DisandriaObjectShare::removeObject);
    mod->addClassMethod(disandriaObjectShareClass, "isObjectAvailable", &dfsapi_DisandriaObjectShare::isObjectAvailable);
}
