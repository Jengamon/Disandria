#ifndef __DISANDRIA_CFSAPI_CEGUI_VECTOR3_H
#define __DISANDRIA_CFSAPI_CEGUI_VECTOR3_H

#include <memory>
#include <falcon/engine.h>
#include <CEGUI/CEGUI.h>

class cfsapi_CEGUI_Vector3f : public Falcon::CoreObject
{
	public:
		static void init(Falcon::VMachine*);
		// No factory, as created program-side.
		static Falcon::CoreObject* factory(const Falcon::CoreClass*, void*, bool);
		
		cfsapi_CEGUI_Vector3f(const Falcon::CoreClass*, CEGUI::Vector3<double>*);
		cfsapi_CEGUI_Vector3f(const cfsapi_CEGUI_Vector3f&);
		
		virtual Falcon::CoreObject* clone() const;
		virtual bool setProperty(const Falcon::String&, const Falcon::Item&);
		virtual bool getProperty(const Falcon::String&, Falcon::Item&) const;
		
		const std::shared_ptr<CEGUI::Vector3<double>> vec() const { return vect; }
		std::shared_ptr<CEGUI::Vector3<double>> vec() { return vect; }
		
		static FALCON_FUNC toString(Falcon::VMachine*);
		
		static FALCON_FUNC __add(Falcon::VMachine*);
		static FALCON_FUNC __sub(Falcon::VMachine*);
		static FALCON_FUNC __mul(Falcon::VMachine*);
	private:
		std::shared_ptr<CEGUI::Vector3<double>> vect;
};

#endif // __DISANDRIA_CFSAPI_CEGUI_VECTOR3_H
