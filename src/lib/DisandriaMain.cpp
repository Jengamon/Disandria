#include "DisandriaMain.h"
#include <fstream>
#include "../helplib/Log.h"

bool Disandria::onInit()
{
    try {
        Poco::AutoPtr<Poco::Util::XMLConfiguration> gConf(new Poco::Util::XMLConfiguration("./conf.xml"));
        GameManager::setGameName(gConf->getString("game[@name]"));
    } catch(...) {
        Poco::AutoPtr<Poco::Util::XMLConfiguration> gConf(new Poco::Util::XMLConfiguration);
        gConf->loadEmpty("config");
        gConf->setString("game[@name]", "disandria");
        gConf->save("./conf.xml");
        Log::log(PE::Logging::WARNING, "conf.xml was produced. Please adjust before rerunning this program.");
        return false;
    }

    try {
        xmlConf = new Poco::Util::XMLConfiguration(GameManager::getGameFolderName() + "project.proj");
    } catch(...) {
        xmlConf = new Poco::Util::XMLConfiguration;
        xmlConf->loadEmpty("config");
        xmlConf->setString("project[@name]", "|insert-name-here|");
        xmlConf->setInt("project.window.width[@value]", 800);
        xmlConf->setInt("project.window.height[@value]", 600);
        xmlConf->setString("project.mainmenu.image[@name]", "|insert-image-name-here|");
        xmlConf->setString("project.mainmenu.music[@name]", "|insert-music-name-here|");
        xmlConf->setString("project.common.button[@name]", "|insert-sound-name-here|");
        xmlConf->setString("project.common.font[@name]", "|insert-font-name-here|");
        xmlConf->save(GameManager::getGameFolderName() + "project.proj");
        Log::log(PE::Logging::WARNING, "project.proj was produced. Please configure it before running this program again.");
        return false;
    }
    if(RenderWindowManager::registerRenderWindow(0, RenderWindowManager::Params::createParam(xmlConf->getInt("project.window.width[@value]"), xmlConf->getInt("project.window.height[@value]"), xmlConf->getString("project[@name]")))) {
        if(RenderWindowManager::linkRegisterToString("ROOT", 0)) {
            rwin = RenderWindowManager::getRenderWindow("ROOT");
        } else {
            Log::log(PE::Logging::WARNING, "Root window could not be set to ROOT.");
            return false;
        }
    } else {
        Log::log(PE::Logging::WARNING, "Root window could not be created.");
        return false;
    }
    GameManager::setRenderWindow(rwin);
    ImageManager::setRenderWindow(rwin);
    MapManager::setRenderWindow(rwin);
    StateManager::setCurrentState(disandria::States::MAINMENU);
    FontManager::setDefaultFont(xmlConf->getString("project.common.font[@name]"));
    sengine = new FalconSAPI();
    sengine->createRuntime();
    sengine->loadFile("main");
    sengine->createVM();
    sengine->loadCoreModule();
    sengine->loadExternalModule(createAppModule());
    sengine->linkRuntime();
    return true;
}

int Disandria::run()
{
    while(rwin->isOpen()) {
        sengine->launch();
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
    return onCleanup();
}

int Disandria::onCleanup()
{
    delete rwin;
    rwin = NULL;
    return 0;
}
