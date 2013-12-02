#include "ScriptSubsystem.h"
#include <Poco/Util/Application.h>
#include "script/ScriptAPILibrary.h"
#include "script/FalconSAPI.h"
#include "GameManager.h"
#include <fstream>

using namespace Poco::Util;

ScriptAPI* ScriptSubsystem::scriptAPI = NULL;

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

    scriptAPI = ScriptAPILibrary::instance->getAPI(scriptLang);
    poco_assert(scriptAPI != NULL);

    scriptAPI->initialize();
    scriptAPI->createBindings();
    if(scriptAPI->scriptRequests() & SubmitType_FILENAME)
    {
		scriptAPI->scriptByFilename("main");
	}
	else
	{
		std::ifstream in(GameManager::getGameFolderName() + "main." + scriptAPI->extension());
		if(scriptAPI->scriptRequests() & SubmitType_FILE)
		{
			scriptAPI->scriptByFile(in);
		}
		else
		{
			std::string contents;
			std::string line;
			while(getline(in, line))
			{
				contents += line;
			}
			scriptAPI->scriptByString(contents);
		}
		in.close();
	}
}

void ScriptSubsystem::uninitialize() 
{
	scriptAPI->destroyBindings();
	scriptAPI->uninitialize();
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
