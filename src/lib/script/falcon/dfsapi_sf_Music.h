#ifndef __DISANDRIA_DFSAPI_SF_MUSIC_H
#define __DISANDRIA_DFSAPI_SF_MUSIC_H

#include <falcon/engine.h>
#include <SFML/Audio.hpp>

class dfsapi_sf_Music : public Falcon::CoreObject
{
	public:
		static void init(Falcon::VMachine*);
		static Falcon::CoreObject* factory(const Falcon::CoreClass*, void*, bool);
		
		dfsapi_sf_Music(const Falcon::CoreClass*, sf::Music*, bool);
		
		virtual Falcon::CoreObject* clone() const;
		virtual bool setProperty(const Falcon::String&, const Falcon::Item&);
		virtual bool getProperty(const Falcon::String&, Falcon::Item&) const;
		
		const sf::Music* music() const { return msc; }
		sf::Music* music() { return msc; }
		
		/* sf::Music methods */
		static FALCON_FUNC openFromFile(Falcon::VMachine*);
		static FALCON_FUNC getDuration(Falcon::VMachine*);
		static FALCON_FUNC play(Falcon::VMachine*);
		static FALCON_FUNC pause(Falcon::VMachine*);
		static FALCON_FUNC stop(Falcon::VMachine*);
		static FALCON_FUNC getStatus(Falcon::VMachine*);
		static FALCON_FUNC setPlayingOffset(Falcon::VMachine*);
		static FALCON_FUNC getPlayingOffset(Falcon::VMachine*);
		static FALCON_FUNC setLoop(Falcon::VMachine*);
		static FALCON_FUNC getLoop(Falcon::VMachine*);
		
		~dfsapi_sf_Music();
	private:
		sf::Music* msc;
		bool controlMusic;
};


#endif // __DISANDRIA_DFSAPI_SF_MUSIC_H
