#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H

#include <SFML/Audio.hpp>
#include <map>
#include <string>

class MusicManager
{
public:
    static sf::Music* createMusic(std::string, std::string);
    static sf::SoundBuffer* createSound(std::string, std::string);
    static sf::Sound makeSound(sf::SoundBuffer*);
    static void deleteMusic(std::string);
    static void deleteSound(std::string);
    static sf::Music* getMusicPointer(std::string);
    static sf::SoundBuffer* getSoundPointer(std::string);
    static void setLoadingPrefix(std::string);
private:
    static std::string loadPrefix;
    static std::map<std::string, sf::Music*> music;
    static std::map<std::string, sf::SoundBuffer*> sound;
};

#endif // MUSICMANAGER_H
