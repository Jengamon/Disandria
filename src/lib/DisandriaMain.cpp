#include "DisandriaMain.h"
#include "../helplib/Log.h"

bool Disandria::onInit()
{
	try
	{
		xmlConf = new Poco::Util::XMLConfiguration("disandria/project.proj");
		rwin = new RenderWindow(xmlConf->getInt("project.window.width[@value]"),
					xmlConf->getInt("project.window.height[@value]"),
					xmlConf->getString("project[@name]"));
		gameMan = new GameManager;
		MusicManager::createMusic("menuMusic", "disandria/" + xmlConf->getString("project.mainmenu.music[@name]"));
	}
	catch(...)
	{
		xmlConf = new Poco::Util::XMLConfiguration;
		xmlConf->loadEmpty("config");
		xmlConf->setString("project[@name]", "<insert-name-here>");
		xmlConf->setInt("project.window.width[@value]", 800);
		xmlConf->setInt("project.window.height[@value]", 600);
		xmlConf->setString("project.mainmenu.image[@name]", "<insert-image-name-here>");
		xmlConf->setString("project.mainmenu.music[@name]", "<insert-music-name-here>");
		xmlConf->setString("project.common.button[@name]", "<insert-sound-name-here>");
		xmlConf->save("disandria/project.proj");
		Log::log(PE::Logging::WARNING, "project.proj was produced. Please configure it before running this program again.");
		return false;
	}
	sf::Music* msc = MusicManager::getMusicPointer("menuMusic");
	msc->setLoop(true);
	msc->setVolume(100);
	msc->play();
	rwin->displayWindow(MenuManager::registerMainMenu(rwin->renderLayout("MainMenu/gui.layout")));
	ImageManager::setRenderWindow(rwin);
	ImageManager::renderImage("mainMenu", disandria::Image::createImage(SpriteFactory::createTexture("disandria/" + xmlConf->getString("project.mainmenu.image[@name]")), -1));
	MapManager::setRenderWindow(rwin);
	return true;
}

int Disandria::run()
{
	while(rwin->isOpen())
	{
		sf::Event event;
		while(rwin->pollEvent(event))
		{
			rwin->handleEvent(event);
		}
		rwin->clear();
		rwin->startRendering();
		if(MapParser::getMapName() != "")
			MapManager::renderMap();
		ImageManager::renders();
		rwin->renderGUI();
		rwin->display();
	}
	return onCleanup();
}

int Disandria::onCleanup()
{
	delete rwin;
	delete gameMan;
	gameMan = NULL;
	rwin = NULL;
	return 0;
}
