#ifndef __DISANDRIA_FALCONSCRIPTINGMODULE_H
#define __DISANDRIA_FALCONSCRIPTINGMODULE_H

#include <falcon/engine.h>
#include <CEGUI/CEGUI.h>

class FalconScriptingModule : public CEGUI::ScriptModule
{
public:
    static FalconScriptingModule* create(Falcon::VMachine* = NULL);
    CEGUI::Event::Connection subscribeEvent(CEGUI::EventSet*, const CEGUI::String&, const CEGUI::String&);
    CEGUI::Event::Connection subscribeEvent(CEGUI::EventSet*, const CEGUI::String&, CEGUI::Event::Group, const CEGUI::String&);
    void executeScriptFile(const CEGUI::String&, const CEGUI::String& = "");
    int executeScriptGlobal(const CEGUI::String&);
    void executeString(const CEGUI::String&);
    bool executeScriptedEventHandler(const CEGUI::String&e, const CEGUI::EventArgs&);
private:
    FalconScriptingModule(Falcon::VMachine*);
    void setModuleIdentifierString();
    Falcon::VMachine* d_vm;
    Falcon::ModuleLoader* d_ml;
    bool d_ownsVM;
};

#endif // __DISANDRIA_FALCONSCRIPTINGMODULE_H
