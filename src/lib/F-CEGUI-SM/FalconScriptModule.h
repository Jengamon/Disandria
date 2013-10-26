#ifndef F_CEGUI_SM_FALCONSCRIPTMODULE
#define F_CEGUI_SM_FALCONSCRIPTMODULE

#include <CEGUI/CEGUI.h>
#include <falcon/engine.h>

class FalconScriptModule : public CEGUI::ScriptModule
{
public:
    /** Construction and destruction **/
    static FalconScriptModule& create(Falcon::VMachine* vm = NULL);
    static void destroy(FalconScriptModule&);

    /** Script execution functions **/
    void executeScriptFile(const CEGUI::String& filename, const CEGUI::String& resourceGroup);
    int executeScriptGlobal(const CEGUI::String& function_name);
    bool executeScriptedEventHandler(const CEGUI::String& handler_name, const CEGUI::EventArgs& e);
    void executeString(const CEGUI::String& str);

    /** Event subscription **/
    CEGUI::Event::Connection subscribeEvent(CEGUI::EventSet* target, const CEGUI::String& name, const CEGUI::String& subscriber_name);
    CEGUI::Event::Connection subscribeEvent(CEGUI::EventSet* target, const CEGUI::String& name, const CEGUI::Event::Group group, const CEGUI::String& subscriber_name);

    /** Bindings creation / destruction **/
    void createBindings();
    void destroyBindings();

    /** Accessor **/
    Falcon::VMachine* getFalconVM() const {
        return d_vm;
    }

    /** Variables and implementation **/
private:
    FalconScriptModule(Falcon::VMachine*);
    ~FalconScriptModule();
    bool d_ownsVM;
    Falcon::VMachine* d_vm;
    Falcon::ModuleLoader* d_m_load;
};

#endif // F_CEGUI_SM_FALCONSCRIPTMODULE
