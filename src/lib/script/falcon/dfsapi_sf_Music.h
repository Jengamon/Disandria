#ifndef __DISANDRIA_DFSAPI_SF_MUSIC_H
#define __DISANDRIA_DFSAPI_SF_MUSIC_H

#include <memory>
#include <falcon/engine.h>
#include <SFML/Audio.hpp>

class dfsapi_sf_Music : public Falcon::CoreObject
{
public:
    static void init(Falcon::VMachine*);
    static Falcon::CoreObject* factory(const Falcon::CoreClass*, void*, bool);

    dfsapi_sf_Music(const Falcon::CoreClass*, sf::Music*);
    dfsapi_sf_Music(const dfsapi_sf_Music&);

    virtual Falcon::CoreObject* clone() const;
    virtual bool setProperty(const Falcon::String&, const Falcon::Item&);
    virtual bool getProperty(const Falcon::String&, Falcon::Item&) const;

    const std::shared_ptr<sf::Music> music() const {
        return msc;
    }
    std::shared_ptr<sf::Music> music() {
        return msc;
    }

    /* sf::Music methods */
    static FALCON_FUNC openFromFile(Falcon::VMachine*);
    static FALCON_FUNC getDuration(Falcon::VMachine*);
    static FALCON_FUNC play(Falcon::VMachine*);
    static FALCON_FUNC pause(Falcon::VMachine*);
    static FALCON_FUNC stop(Falcon::VMachine*);
    static FALCON_FUNC getChannelCount(Falcon::VMachine*);
    static FALCON_FUNC getSampleRate(Falcon::VMachine*);
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
    std::shared_ptr<sf::Music> msc;
};


#endif // __DISANDRIA_DFSAPI_SF_MUSIC_H
