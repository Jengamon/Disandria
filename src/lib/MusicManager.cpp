#include "MusicManager.h"
#include "../helplib/Log.h"

std::string MusicManager::loadPrefix;
std::map<std::string, sf::Music*> MusicManager::music;
std::map<std::string, sf::SoundBuffer*> MusicManager::sound;

void MusicManager::setLoadingPrefix(std::string pref)
{
    loadPrefix = pref;
}

sf::Music* MusicManager::createMusic(std::string name, std::string str)
{
    sf::Music* msc = new sf::Music;
    if(!msc->openFromFile(loadPrefix + str)) {
        Log::log("Failed to open " + loadPrefix + str);
    }

    if(!(music.find(name) == music.end())) {
        delete music[name];
    }
    music[name] = msc;
    return msc;
}


sf::SoundBuffer* MusicManager::createSound(std::string name, std::string str)
{
    sf::SoundBuffer* sndbf = new sf::SoundBuffer;
    if(!sndbf->loadFromFile(loadPrefix + str)) {
        Log::log("Failed to open " + loadPrefix + str);
    }
    if(!(sound.find(name) == sound.end())) {
        delete sound[name];
    }
    sound[name] = sndbf;
    return sndbf;
}

sf::Sound MusicManager::makeSound(sf::SoundBuffer* snd)
{
    sf::Sound sound(*snd);
    return sound;
}

void MusicManager::deleteMusic(std::string name)
{
    if(music.find(name) != music.end()) {
        delete music.find(name)->second;
        music.erase(music.find(name));
    }
}

void MusicManager::deleteSound(std::string name)
{
    if(sound.find(name) != sound.end()) {
        delete sound.find(name)->second;
        sound.erase(sound.find(name));
    }
}

sf::Music* MusicManager::getMusicPointer(std::string name)
{
    if(music.find(name) != music.end()) {
        return music.find(name)->second;
    } else {
        return NULL;
    }
}

sf::SoundBuffer* MusicManager::getSoundPointer(std::string name)
{
    if(sound.find(name) != sound.end()) {
        return sound.find(name)->second;
    } else {
        return NULL;
    }
}
