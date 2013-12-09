#include "Menus.h"
#include "StateManager.h"

bool MAINMENU_startButton(const CEGUI::EventArgs&)
{
    StateManager::setCurrentState(disandria::States::MAINGAME);
}

bool MAINMENU_loadButton(const CEGUI::EventArgs&)
{
    // TODO: Do something
}
