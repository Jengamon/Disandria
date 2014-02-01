#include "cfsapi_CEGUI_Vector2f.h"
#include <Poco/Foundation.h>

void cfsapi_CEGUI_Vector2f::init(Falcon::VMachine* vm)
{
    cfsapi_CEGUI_Vector2f* self = Falcon::dyncast<cfsapi_CEGUI_Vector2f*>(vm->self().asObject());
    Falcon::Item* dxov = vm->param(0);
    Falcon::Item* dy = vm->param(1);
    if(dxov != NULL) {
        if(dxov->isObject()) {
            cfsapi_CEGUI_Vector2f* o = Falcon::dyncast<cfsapi_CEGUI_Vector2f*>(dxov->asObject());
            self->vect = o->vect;
        } else if(dxov->isOrdinal() && (dy != NULL && dy->isOrdinal())) {
            double x = dxov->forceNumeric();
            double y = dy->forceNumeric();
            self->vect.reset(new CEGUI::Vector2<double>(x, y));
        }
    }
}

Falcon::CoreObject* cfsapi_CEGUI_Vector2f::factory(const Falcon::CoreClass* gen, void* ud, bool dsr)
{
    if(ud != 0)
        return new cfsapi_CEGUI_Vector2f(gen, reinterpret_cast<CEGUI::Vector2<double>*>(ud));
    else
        return new cfsapi_CEGUI_Vector2f(gen, new CEGUI::Vector2<double>(0, 0));
}

cfsapi_CEGUI_Vector2f::cfsapi_CEGUI_Vector2f(const Falcon::CoreClass* gen, CEGUI::Vector2<double>* vec) : Falcon::CoreObject(gen), vect(vec)
{
    poco_assert(vec != NULL);
}

cfsapi_CEGUI_Vector2f::cfsapi_CEGUI_Vector2f(const cfsapi_CEGUI_Vector2f& o) : Falcon::CoreObject(o), vect(o.vect)
{
}

Falcon::CoreObject* cfsapi_CEGUI_Vector2f::clone() const
{
    return new cfsapi_CEGUI_Vector2f(*this);
}

bool cfsapi_CEGUI_Vector2f::setProperty(const Falcon::String& prop, const Falcon::Item& vl)
{
    if(!vl.isOrdinal())
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("N"));

    if(prop == "x")
        vect->d_x = vl.forceNumeric();
    else if(prop == "y")
        vect->d_y = vl.forceNumeric();
    else {
        /*if(prop == "x")
            throw new Falcon::AccessError(Falcon::ErrorParam(Falcon::e_prop_ro).extra(prop));*/
        return false;
    }
    return true;
}

bool cfsapi_CEGUI_Vector2f::getProperty(const Falcon::String& key, Falcon::Item& ret) const
{
    if(key == "x")
        ret = vect->d_x;
    else if(key == "y")
        ret = vect->d_y;
    else
        return defaultProperty(key, ret);
    return true;
}

FALCON_FUNC cfsapi_CEGUI_Vector2f::toString(Falcon::VMachine* vm)
{
    cfsapi_CEGUI_Vector2f* self = Falcon::dyncast<cfsapi_CEGUI_Vector2f*>(vm->self().asObject());

    Falcon::String* rt = new Falcon::CoreString();
    rt->N(self->vec()->d_x, "%g").A(" ").N(self->vec()->d_y, "%g");

    vm->retval(rt);
}

FALCON_FUNC  cfsapi_CEGUI_Vector2f::__add(Falcon::VMachine* vm)
{
    // Set up and get param
    cfsapi_CEGUI_Vector2f* self = Falcon::dyncast<cfsapi_CEGUI_Vector2f*>(vm->self().asObject());
    Falcon::Item* oit = vm->param(0);

    // Validate param
    if(oit == NULL || !oit->isObject())
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("CEGUIVector2f"));

    // Cast param to proper type
    cfsapi_CEGUI_Vector2f* other = Falcon::dyncast<cfsapi_CEGUI_Vector2f*>(oit->asObject());

    // Create result
    Falcon::Item* cv2fci = vm->findWKI("CEGUIVector2f");
    cfsapi_CEGUI_Vector2f* nvc = new cfsapi_CEGUI_Vector2f(cv2fci->asClass(), new CEGUI::Vector2<double>(*self->vec() + *other->vec()));
    vm->retval(nvc);
}

FALCON_FUNC  cfsapi_CEGUI_Vector2f::__sub(Falcon::VMachine* vm)
{
    // Set up and get param
    cfsapi_CEGUI_Vector2f* self = Falcon::dyncast<cfsapi_CEGUI_Vector2f*>(vm->self().asObject());
    Falcon::Item* oit = vm->param(0);

    // Validate param
    if(oit == NULL || !oit->isObject())
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("CEGUIVector2f"));

    // Cast param to proper type
    cfsapi_CEGUI_Vector2f* other = Falcon::dyncast<cfsapi_CEGUI_Vector2f*>(oit->asObject());

    // Create result
    Falcon::Item* cv2fci = vm->findWKI("CEGUIVector2f");
    cfsapi_CEGUI_Vector2f* nvc = new cfsapi_CEGUI_Vector2f(cv2fci->asClass(), new CEGUI::Vector2<double>(*self->vec() - *other->vec()));
    vm->retval(nvc);
}

FALCON_FUNC  cfsapi_CEGUI_Vector2f::__mul(Falcon::VMachine* vm)
{
    // Set up and get param
    cfsapi_CEGUI_Vector2f* self = Falcon::dyncast<cfsapi_CEGUI_Vector2f*>(vm->self().asObject());
    Falcon::Item* oit = vm->param(0);

    // Validate param
    if(oit == NULL || !oit->isObject())
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("CEGUIVector2f"));

    // Cast param to proper type
    cfsapi_CEGUI_Vector2f* other = Falcon::dyncast<cfsapi_CEGUI_Vector2f*>(oit->asObject());

    // Create result
    Falcon::Item* cv2fci = vm->findWKI("CEGUIVector2f");
    cfsapi_CEGUI_Vector2f* nvc = new cfsapi_CEGUI_Vector2f(cv2fci->asClass(), new CEGUI::Vector2<double>(*self->vec() **other->vec()));
    vm->retval(nvc);
}

FALCON_FUNC  cfsapi_CEGUI_Vector2f::__div(Falcon::VMachine* vm)
{
    // Set up and get param
    cfsapi_CEGUI_Vector2f* self = Falcon::dyncast<cfsapi_CEGUI_Vector2f*>(vm->self().asObject());
    Falcon::Item* oit = vm->param(0);

    // Validate param
    if(oit == NULL || !oit->isObject())
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("CEGUIVector2f"));

    // Cast param to proper type
    cfsapi_CEGUI_Vector2f* other = Falcon::dyncast<cfsapi_CEGUI_Vector2f*>(oit->asObject());

    // Create result
    Falcon::Item* cv2fci = vm->findWKI("CEGUIVector2f");
    cfsapi_CEGUI_Vector2f* nvc = new cfsapi_CEGUI_Vector2f(cv2fci->asClass(), new CEGUI::Vector2<double>(*self->vec() / *other->vec()));
    vm->retval(nvc);
}
