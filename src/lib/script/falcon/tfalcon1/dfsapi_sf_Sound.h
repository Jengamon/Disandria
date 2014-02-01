#ifndef __DISANDRIA_DFSAPI_SF_SOUND_H
#define __DISANDRIA_DFSAPI_SF_SOUND_H

#include <memory>
#include <falcon/engine.h>
#include <SFML/Audio.hpp>

class dfsapi_sf_Sound : public Falcon::CoreObject
{
public:
    static void init(Falcon::VMachine*);
    static Falcon::CoreObject* factory(const Falcon::CoreClass*, void*, bool);

    dfsapi_sf_Sound(const Falcon::CoreClass*, sf::Sound*);
    dfsapi_sf_Sound(const dfsapi_sf_Sound&);

    ~dfsapi_sf_Sound();

    virtual Falcon::CoreObject* clone() const;
    virtual bool setProperty(const Falcon::String&, const Falcon::Item&);
    virtual bool getProperty(const Falcon::String&, Falcon::Item&) const;

    const std::shared_ptr<sf::Sound> sound() const {
        return snd;
    }
    std::shared_ptr<sf::Sound> sound() {
        return snd;
    }

    /* sf::Sound methods */
    static FALCON_FUNC setBuffer(Falcon::VMachine*);
    static FALCON_FUNC getBuffer(Falcon::VMachine*);
    static FALCON_FUNC play(Falcon::VMachine*);
    static FALCON_FUNC pause(Falcon::VMachine*);
    static FALCON_FUNC stop(Falcon::VMachine*);
    static FALCON_FUNC getStatus(Falcon::VMachine*);
    static FALCON_FUNC setPlayingOffset(Falcon::VMachine*);
    static FALCON_FUNC getPlayingOffset(Falcon::VMachine*);
    static FALCON_FUNC setLoop(Falcon::VMachine*);
    static FALCON_FUNC getLoop(Falcon::VMachine*);
    static FALCON_FUNC setPitch(Falcon::VMachine*);
    static FALCON_FUNC getPitch(Falcon::VMachine*);
    static FALCON_FUNC setVolume(Falcon::VMachine*);
    static FALCON_FUNC getVolume(Falcon::VMachine*);

private:
    std::shared_ptr<sf::Sound> snd;
    Falcon::GarbageLock* lck;
};


#endif // __DISANDRIA_DFSAPI_SF_SOUND_H
