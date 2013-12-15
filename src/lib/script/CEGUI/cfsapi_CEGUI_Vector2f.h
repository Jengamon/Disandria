#ifndef __DISANDRIA_CFSAPI_CEGUI_VECTOR2_H
#define __DISANDRIA_CFSAPI_CEGUI_VECTOR2_H

#include <memory>
#include <falcon/engine.h>
#include <CEGUI/CEGUI.h>

class cfsapi_CEGUI_Vector2f : public Falcon::CoreObject
{
	public:
		static void init(Falcon::VMachine*);
		// No factory, as created program-side.
		static Falcon::CoreObject* factory(const Falcon::CoreClass*, void*, bool);
		
		cfsapi_CEGUI_Vector2f(const Falcon::CoreClass*, CEGUI::Vector2<double>*);
		cfsapi_CEGUI_Vector2f(const cfsapi_CEGUI_Vector2f&);
		
		virtual Falcon::CoreObject* clone() const;
		virtual bool setProperty(const Falcon::String&, const Falcon::Item&);
		virtual bool getProperty(const Falcon::String&, Falcon::Item&) const;
		
		const std::shared_ptr<CEGUI::Vector2<double>> vec() const { return vect; }
		std::shared_ptr<CEGUI::Vector2<double>> vec() { return vect; }
		
		static FALCON_FUNC toString(Falcon::VMachine*);
		
		static FALCON_FUNC __add(Falcon::VMachine*);
		static FALCON_FUNC __sub(Falcon::VMachine*);
		static FALCON_FUNC __mul(Falcon::VMachine*);
		static FALCON_FUNC __div(Falcon::VMachine*);
	private:
		std::shared_ptr<CEGUI::Vector2<double>> vect;
};

#endif // __DISANDRIA_CFSAPI_CEGUI_VECTOR2_H
