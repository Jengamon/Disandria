#include "ScriptSubsystem.h"
#include <Poco/Util/Application.h>
#include "script/ScriptAPILibrary.h"
#include "script/FalconSAPI.h"
#include "GameManager.h"
#include <fstream>

using namespace Poco::Util;

void ScriptSubsystem::initialize(Application& app)
{
    std::string scriptLang = app.config().getString("project.sys.script.lang", "");
    if(scriptLang == "") {
        scriptLang = app.config().getString("project.script.lang");
        if(scriptLang == "") {
            app.logger().error("Scripting language of project not specified. Assuming to be Falcon.");
            scriptLang = "Falcon";
        }
    }
    ScriptAPILibrary::instance = new ScriptAPILibrary;
    ScriptAPILibrary::instance->addAPI("Falcon", new FalconSAPI);

    ScriptAPILibrary::instance->scriptAPI = ScriptAPILibrary::instance->getAPI(scriptLang);
    ScriptAPILibrary::instance->initialize();
}

void ScriptSubsystem::uninitialize()
{
    ScriptAPILibrary::instance->cleanup();
}

void ScriptSubsystem::defineOptions(OptionSet& opst)
{
    opst.addOption(
        Option("scriptLanguage", "", "Set scripting language")
        .required(false)
        .argument("name")
        .repeatable(false)
        .group("script")
        .binding("project.sys.script.lang"));
}

const char* ScriptSubsystem::name() const
{
    return "Disandria ScriptSubsystem";
}
