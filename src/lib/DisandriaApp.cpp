#include "DisandriaApp.h"
#include <Poco/Util/HelpFormatter.h>
#include <iostream>
#include <cstdlib>
#include <Poco/Foundation.h>
#include <Poco/Util/XMLConfiguration.h>
#include "RenderWindowManager.h"
#include "MusicManager.h"
#include "MenuManager.h"
#include "MapManager.h"
#include "ImageManager.h"
#include "StatesManager.h"
#include "FontManager.h"
#include "GameTimer.h"
#include "GameManager.h"
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

    StateManager::setCurrentState(disandria::States::MAINMENU);
    FontManager::setDefaultFont(xmlConf->getString("project.common.font[@name]"));

    Application::initialize(self);
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
    std::cout << config().getString("system.osName") << std::endl;
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
    this->logger().notice("Disandria v.0.1");
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
