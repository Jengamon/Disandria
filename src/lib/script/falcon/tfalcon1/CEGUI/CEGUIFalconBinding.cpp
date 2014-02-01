#include "CEGUIFalconBinding.h"

#include "cfsapi_functions.h"

#include "cfsapi_CEGUI_Vector2f.h"
#include "cfsapi_CEGUI_Vector3f.h"

Falcon::Module* CEGUIFalconBinding::module = NULL;

void CEGUIFalconBinding::addConstants(Falcon::Module* mod)
{
}

void CEGUIFalconBinding::addMethods(Falcon::Module* mod)
{
}

void CEGUIFalconBinding::addClasses(Falcon::Module* mod)
{
    Falcon::Symbol* CEGUIVector2f = mod->addClass("CEGUIVector2f", &cfsapi_CEGUI_Vector2f::init)->addParam("x")->addParam("y");
    CEGUIVector2f->setWKS(true);
    CEGUIVector2f->getClassDef()->factory(&cfsapi_CEGUI_Vector2f::factory);
    mod->addClassMethod(CEGUIVector2f, "toString", &cfsapi_CEGUI_Vector2f::toString);
    mod->addClassMethod(CEGUIVector2f, "__add", &cfsapi_CEGUI_Vector2f::__add);
    mod->addClassMethod(CEGUIVector2f, "__sub", &cfsapi_CEGUI_Vector2f::__sub);
    mod->addClassMethod(CEGUIVector2f, "__mul", &cfsapi_CEGUI_Vector2f::__mul);
    mod->addClassMethod(CEGUIVector2f, "__div", &cfsapi_CEGUI_Vector2f::__div);
    mod->addClassProperty(CEGUIVector2f, "x");
    mod->addClassProperty(CEGUIVector2f, "y");

    Falcon::Symbol* CEGUIVector3f = mod->addClass("CEGUIVector3f", &cfsapi_CEGUI_Vector3f::init)->addParam("x")->addParam("y")->addParam("z");
    CEGUIVector3f->setWKS(true);
    CEGUIVector3f->getClassDef()->factory(&cfsapi_CEGUI_Vector3f::factory);
    mod->addClassMethod(CEGUIVector3f, "toString", &cfsapi_CEGUI_Vector3f::toString);
    mod->addClassMethod(CEGUIVector3f, "__add", &cfsapi_CEGUI_Vector3f::__add);
    mod->addClassMethod(CEGUIVector3f, "__sub", &cfsapi_CEGUI_Vector3f::__sub);
    mod->addClassMethod(CEGUIVector3f, "__mul", &cfsapi_CEGUI_Vector3f::__mul);
    mod->addClassProperty(CEGUIVector3f, "x");
    mod->addClassProperty(CEGUIVector3f, "y");
    mod->addClassProperty(CEGUIVector3f, "z");
}

void CEGUIFalconBinding::addSingletons(Falcon::Module* mod)
{
    Falcon::Symbol* guiSingleton = mod->addSingleton("CEGUI");
    Falcon::Symbol* guiClass = guiSingleton->getInstance();
    mod->addClassMethod(guiClass, "renderLayout", &renderLayout);
}

Falcon::Module* CEGUIFalconBinding::createBinding()
{
    if(module == NULL) {
        module = new Falcon::Module;
        module->name("CEGUIFalcon");
        addConstants(module);
        addMethods(module);
        addClasses(module);
        addSingletons(module);
    }
    return module;
}
