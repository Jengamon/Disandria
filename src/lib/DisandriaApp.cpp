#include "DisandriaApp.h"
#include <Poco/Util/HelpFormatter.h>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <Poco/Foundation.h>
#include <Poco/Util/XMLConfiguration.h>
#include "RenderWindowManager.h"
#include "MenuManager.h"
#include "MapManager.h"
#include "ImageManager.h"
#include "StatesManager.h"
#include "FontManager.h"
#include "GameTimer.h"
#include "GameManager.h"
#include "script/ScriptAPILibrary.h"

using namespace Poco::Util;

void DisandriaApp::initialize(Application& self)
{
    loadConfiguration();
    std::string loc = config().getString("game.location", "nil");
    if(loc == "nil") {
        loc = config().getString("game[@location]", "nil");
        if(loc == "nil") {
            logger().error("Project not specified.");
            displayHelp();
            exit(-1);
        }
    }
    GameManager::setGameName(loc);
    Poco::AutoPtr<XMLConfiguration> xmlConf;
    try {
        xmlConf = new XMLConfiguration(GameManager::getGameFolderName() + "project.proj");
    } catch(...) {
        logger().error("Invalid project.");
        exit(-1);
    }

    config().setString("project.name", xmlConf->getString("project[@name]", ""));
    config().setInt("project.window.width", xmlConf->getInt("project.window.width[@value]", 0));
    config().setInt("project.window.height", xmlConf->getInt("project.window.height[@value]", 0));
    config().setString("project.script.lang", xmlConf->getString("project.script.lang[@value]", ""));

    StateManager::setCurrentState(disandria::States::MAINMENU);
    FontManager::setDefaultFont(xmlConf->getString("project.common.font[@name]"));

    Application::initialize(self);
    /* Example of a (partially) proper way to use ScriptAPILibrary and ScriptAPI
        ScriptAPI* api = ScriptAPILibrary::instance->getAPI("Falcon");
        api->initialize();
        api->createBindings();
        api->scriptByFilename("main");
        api->destroyBindings();
        api->uninitialize();
        api = NULL;
    */
    rwin = RenderWindowManager::getRenderWindow("ROOT");
}

void DisandriaApp::reinitialize(Application& self)
{
    Application::reinitialize(self);
}

const char* DisandriaApp::name() const
{
    return "Disandria";
}

void DisandriaApp::uninitialize()
{
    Application::uninitialize();
    rwin = NULL;
}

void DisandriaApp::defineOptions(OptionSet& opst)
{
    Application::defineOptions(opst);
    opst.addOption(
        Option("version", "v", "Display current Disandria version")
        .required(false)
        .repeatable(false)
        .group("info")
        .callback(OptionCallback<DisandriaApp>(this, &DisandriaApp::handleVersion)));

    opst.addOption(
        Option("help", "h", "Display help")
        .required(false)
        .repeatable(false)
        .group("info")
        .callback(OptionCallback<DisandriaApp>(this, &DisandriaApp::handleHelp)));

    opst.addOption(
        Option("project", "p", "Load project at this path")
        .required(false)
        .argument("location")
        .repeatable(false)
        .binding("game.location"));
}

int DisandriaApp::main(const std::vector<std::string>& args)
{
    ScriptAPILibrary::instance->runScript("main");
    while(rwin->isOpen()) {
        sf::Event event;
        while(rwin->pollEvent(event)) {
            rwin->handleEvent(event);
        }
        rwin->clearWindow();
        rwin->startRendering();
        StatesManager::checkCurrentState(rwin);
        StatesManager::renderCurrentState(rwin);
        MapManager::renderMap();
        ImageManager::renders();
        if(GameTimer::isRunning())
            GameTimer::renderTime(rwin);
        GameTimer::update();
        rwin->renderGUI();
        rwin->display();
    }

    return Application::EXIT_OK;
}

void DisandriaApp::handleVersion(const std::string& name, const std::string& value)
{
    std::stringstream version; version << GameManager::getEngineVersion();
    this->logger().notice("Disandria v." + version.str());
    stopOptionsProcessing();
    exit(-1);
}

void DisandriaApp::displayHelp()
{
    HelpFormatter form(options());
    form.setCommand(commandName());
    form.setUsage("OPTIONS");
    form.setHeader("The Disandria Game Engine");
    form.format(std::cout);
}

void DisandriaApp::handleHelp(const std::string& name, const std::string& value)
{
    displayHelp();
    stopOptionsProcessing();
    exit(-1);
}
