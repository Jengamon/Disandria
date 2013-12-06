#ifndef __DISANDRIA_CFSAPI_CEGUI_WINDOW_H
#define __DISANDRIA_CFSAPI_CEGUI_WINDOW_H

#include <memory>
#include <falcon/engine.h>
#include <CEGUI/CEGUI.h>
/*
class cfsapi_CEGUI_Window : public Falcon::CoreObject
{
	public:
		static void init(Falcon::VMachine*);
		// No factory, as created program-side.
		//static Falcon::CoreObject* factory(const Falcon::CoreClass*, void*, bool);
		
		cfsapi_CEGUI_Window(const Falcon::CoreClass*, CEGUI::Window*);
		cfsapi_CEGUI_Window(const cfsapi_CEGUI_Window&);
		
		virtual Falcon::CoreObject* clone() const;
		virtual bool setProperty(const Falcon::String&, const Falcon::Item&);
		virtual bool getProperty(const Falcon::String&, Falcon::Item&);
		
		const std::shared_ptr<CEGUI::Window> window() const { return win; }
		std::shared_ptr<CEGUI::Window> window() { return win; }
	private:
		std::shared_ptr<CEGUI::Window> win;
};
*/
#endif // __DISANDRIA_CFSAPI_CEGUI_WINDOW_H