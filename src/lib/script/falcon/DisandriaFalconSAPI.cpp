#include "DisandriaFalconSAPI.h"

/* Bindings to Disandria C++ classes */
#include "dfsapi_MusicManager.h"
#include "dfsapi_GameManager.h"

/* Bindings to SFML C++ classes (underlying classes of Disandria) */
#include "dfsapi_sf_Music.h"
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

}

void DisandriaFalconSAPI::addClasses(Falcon::Module* mod)
{
    /* sf::Music */
    Falcon::Symbol* sfMusic = mod->addClass("sfMusic", &dfsapi_sf_Music::init)->addParam("musicPointer");
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
}

void DisandriaFalconSAPI::addSingletons(Falcon::Module* mod)
{
    /* MusicManager
    Falcon::Symbol* musicManagerSingleton = mod->addSingleton("MusicManager");
    Falcon::Symbol* musicManagerClass = musicManagerSingleton->getInstance();
    mod->addClassMethod(musicManagerClass, "createMusic", &dfsapi_MusicManager_createMusic);*/

    /* GameManager */
    Falcon::Symbol* gameManagerSingleton = mod->addSingleton("GameManager");
    Falcon::Symbol* gameManagerClass = gameManagerSingleton->getInstance();
    mod->addClassMethod(gameManagerClass, "getGameFolderName", &dfsapi_GameManager_getGameFolderName);
    mod->addClassMethod(gameManagerClass, "getEngineVersion", &dfsapi_GameManager_getEngineVersion);
}
