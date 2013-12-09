#include "MenuManager.h"
#include "Menus.h"

CEGUI::Window* MenuManager::registerMainMenu(CEGUI::Window* window)
{
    CEGUI::Window* frame = window->getChild("MAIN");
    frame->getChild("START")->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(MAINMENU_startButton));
    frame->getChild("LOAD")->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(MAINMENU_loadButton));
    return window;
}
