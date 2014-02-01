#include "cfsapi_CEGUI_Vector3f.h"
#include "cfsapi_CEGUI_Vector2f.h"
#include <Poco/Foundation.h>

void cfsapi_CEGUI_Vector3f::init(Falcon::VMachine* vm)
{
    cfsapi_CEGUI_Vector3f* self = Falcon::dyncast<cfsapi_CEGUI_Vector3f*>(vm->self().asObject());
    Falcon::Item* dxov = vm->param(0);
    Falcon::Item* dy = vm->param(1);
    Falcon::Item* dz = vm->param(2);
    if(dxov != NULL) {
        if(dxov->isObject()) {
            if(dy != NULL && dy->isOrdinal()) {
                cfsapi_CEGUI_Vector2f* o = Falcon::dyncast<cfsapi_CEGUI_Vector2f*>(dxov->asObject());
                double z = dy->forceNumeric();
                self->vect.reset(new CEGUI::Vector3<double>(*o->vec(), z));
            } else {
                cfsapi_CEGUI_Vector3f* o = Falcon::dyncast<cfsapi_CEGUI_Vector3f*>(dxov->asObject());
                self->vect = o->vect;
            }
        } else if(dxov->isOrdinal() && (dy != NULL && dy->isOrdinal())) {
            if(dz != NULL && dz->isOrdinal()) {
                double x = dxov->forceNumeric();
                double y = dy->forceNumeric();
                double z = dz->forceNumeric();
                self->vect.reset(new CEGUI::Vector3<double>(x, y, z));
            } else {
                double x = dxov->forceNumeric();
                double y = dy->forceNumeric();
                self->vect.reset(new CEGUI::Vector3<double>(x, y, 0));
            }
        }
    }
}

Falcon::CoreObject* cfsapi_CEGUI_Vector3f::factory(const Falcon::CoreClass* gen, void* ud, bool dsr)
{
    if(ud != 0)
        return new cfsapi_CEGUI_Vector3f(gen, reinterpret_cast<CEGUI::Vector3<double>*>(ud));
    else
        return new cfsapi_CEGUI_Vector3f(gen, new CEGUI::Vector3<double>(0, 0, 0));
}

cfsapi_CEGUI_Vector3f::cfsapi_CEGUI_Vector3f(const Falcon::CoreClass* gen, CEGUI::Vector3<double>* vec) : Falcon::CoreObject(gen), vect(vec)
{
    poco_assert(vec != NULL);
}

cfsapi_CEGUI_Vector3f::cfsapi_CEGUI_Vector3f(const cfsapi_CEGUI_Vector3f& o) : Falcon::CoreObject(o), vect(o.vect)
{
}

Falcon::CoreObject* cfsapi_CEGUI_Vector3f::clone() const
{
    return new cfsapi_CEGUI_Vector3f(*this);
}

bool cfsapi_CEGUI_Vector3f::setProperty(const Falcon::String& prop, const Falcon::Item& vl)
{
    if(!vl.isOrdinal())
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("N"));

    if(prop == "x")
        vect->d_x = vl.forceNumeric();
    else if(prop == "y")
        vect->d_y = vl.forceNumeric();
    else if(prop == "z")
        vect->d_z = vl.forceNumeric();
    else {
        /*if(prop == "x")
            throw new Falcon::AccessError(Falcon::ErrorParam(Falcon::e_prop_ro).extra(prop));*/
        return false;
    }
    return true;
}

bool cfsapi_CEGUI_Vector3f::getProperty(const Falcon::String& key, Falcon::Item& ret) const
{
    if(key == "x")
        ret = vect->d_x;
    else if(key == "y")
        ret = vect->d_y;
    else if(key == "z")
        ret = vect->d_z;
    else
        return defaultProperty(key, ret);
    return true;
}

FALCON_FUNC cfsapi_CEGUI_Vector3f::toString(Falcon::VMachine* vm)
{
    cfsapi_CEGUI_Vector3f* self = Falcon::dyncast<cfsapi_CEGUI_Vector3f*>(vm->self().asObject());

    Falcon::String* rt = new Falcon::CoreString();
    rt->N(self->vec()->d_x, "%g").A(" ").N(self->vec()->d_y, "%g").A(" ").N(self->vec()->d_z, "%g");

    vm->retval(rt);
}

FALCON_FUNC  cfsapi_CEGUI_Vector3f::__add(Falcon::VMachine* vm)
{
    // Set up and get param
    cfsapi_CEGUI_Vector3f* self = Falcon::dyncast<cfsapi_CEGUI_Vector3f*>(vm->self().asObject());
    Falcon::Item* oit = vm->param(0);

    // Validate param
    if(oit == NULL || !oit->isObject())
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("CEGUIVector3f"));

    // Cast param to proper type
    cfsapi_CEGUI_Vector3f* other = Falcon::dyncast<cfsapi_CEGUI_Vector3f*>(oit->asObject());

    // Create result
    Falcon::Item* cv3fci = vm->findWKI("CEGUIVector3f");
    cfsapi_CEGUI_Vector3f* nvc = new cfsapi_CEGUI_Vector3f(cv3fci->asClass(), new CEGUI::Vector3<double>(*self->vec() + *other->vec()));
    vm->retval(nvc);
}

FALCON_FUNC  cfsapi_CEGUI_Vector3f::__sub(Falcon::VMachine* vm)
{
    // Set up and get param
    cfsapi_CEGUI_Vector3f* self = Falcon::dyncast<cfsapi_CEGUI_Vector3f*>(vm->self().asObject());
    Falcon::Item* oit = vm->param(0);

    // Validate param
    if(oit == NULL || !oit->isObject())
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("CEGUIVector3f"));

    // Cast param to proper type
    cfsapi_CEGUI_Vector3f* other = Falcon::dyncast<cfsapi_CEGUI_Vector3f*>(oit->asObject());

    // Create result
    Falcon::Item* cv3fci = vm->findWKI("CEGUIVector3f");
    cfsapi_CEGUI_Vector3f* nvc = new cfsapi_CEGUI_Vector3f(cv3fci->asClass(), new CEGUI::Vector3<double>(*self->vec() - *other->vec()));
    vm->retval(nvc);
}

FALCON_FUNC  cfsapi_CEGUI_Vector3f::__mul(Falcon::VMachine* vm)
{
    // Set up and get param
    cfsapi_CEGUI_Vector3f* self = Falcon::dyncast<cfsapi_CEGUI_Vector3f*>(vm->self().asObject());
    Falcon::Item* oit = vm->param(0);

    // Validate param
    if(oit == NULL || !oit->isOrdinal())
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("N"));

    // Cast param to proper type
    double other = oit->forceNumeric();

    // Create result
    Falcon::Item* cv3fci = vm->findWKI("CEGUIVector3f");
    cfsapi_CEGUI_Vector3f* nvc = new cfsapi_CEGUI_Vector3f(cv3fci->asClass(), new CEGUI::Vector3<double>(*self->vec() * other));
    vm->retval(nvc);
}
