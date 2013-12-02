#ifndef __DISANDRIA_DFSAPI_SF_SOUNDBUFFER_H
#define __DISANDRIA_DFSAPI_SF_SOUNDBUFFER_H

#include <memory>
#include <falcon/engine.h>
#include <SFML/Audio.hpp>

class dfsapi_sf_SoundBuffer : public Falcon::CoreObject
{
public:
    static void init(Falcon::VMachine*);
    static Falcon::CoreObject* factory(const Falcon::CoreClass*, void*, bool);

    dfsapi_sf_SoundBuffer(const Falcon::CoreClass*, sf::SoundBuffer*);
    dfsapi_sf_SoundBuffer(const dfsapi_sf_SoundBuffer&);

    virtual Falcon::CoreObject* clone() const;
    virtual bool setProperty(const Falcon::String&, const Falcon::Item&);
    virtual bool getProperty(const Falcon::String&, Falcon::Item&) const;

    const std::shared_ptr<sf::SoundBuffer> soundbuffer() const {
        return sndbuf;
    }
    std::shared_ptr<sf::SoundBuffer> soundbuffer() {
        return sndbuf;
    }
    
    static FALCON_FUNC loadFromFile(Falcon::VMachine*);
    static FALCON_FUNC getDuration(Falcon::VMachine*);
    static FALCON_FUNC getChannelCount(Falcon::VMachine*);
    static FALCON_FUNC getSampleRate(Falcon::VMachine*);
private:
    std::shared_ptr<sf::SoundBuffer> sndbuf;
};

#endif // __DISANDRIA_DFSAPI_SF_SOUNDBUFFER_H
