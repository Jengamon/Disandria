#include "Menus.h"
#include "StateManager.h"
#include <cstdlib>

bool MAINMENU_startButton(const CEGUI::EventArgs&)
{
	StateManager::setCurrentState(disandria::States::MAINGAME);
}

bool MAINMENU_loadButton(const CEGUI::EventArgs&)
{
	// TODO: Do something
}

bool MAINMENU_endButton(const CEGUI::EventArgs&)
{
	exit(0);
}
