#include "MainMenuState.h"
#include "../MenuManager.h"
#include "../ImageManager.h"
#include "../SpriteFactory.h"
#include "../GameManager.h"
#include <Poco/AutoPtr.h>
#include <Poco/Util/XMLConfiguration.h>

std::string MainMenuState::name()
{
    return "MAINMENU";
}

bool MainMenuState::onInit(RenderWindow* window)
{
    Poco::AutoPtr<Poco::Util::XMLConfiguration> xmlConf = new Poco::Util::XMLConfiguration(GameManager::getGameFolderName() + "project.proj");
    ImageManager::renderImage("mainMenu", disandria::Image::createImage(SpriteFactory::createTexture(GameManager::getGameFolderName() + xmlConf->getString("project.mainmenu.image[@name]")), -1));
    window->displayWindow(MenuManager::registerMainMenu(window->renderLayout("MainMenu/gui.layout")));
}

void MainMenuState::onRender(RenderWindow* win)
{
}

void MainMenuState::onCleanup(RenderWindow* win)
{
    win->displayWindow(NULL);
    ImageManager::deleteImage("mainMenu");
}
