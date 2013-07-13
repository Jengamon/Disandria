#include "Menus.h"
#include "ImageManager.h"
#include "MapParser.h"
#include "MusicManager.h"
#include <cstdlib>

bool MAINMENU_startButton(const CEGUI::EventArgs&)
{
	CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(NULL);
	ImageManager::deleteImage("mainMenu");
	MapParser::loadCurrentMap("testmap");
	MusicManager::getMusicPointer("menuMusic")->stop();
	MusicManager::deleteMusic("menuMusic");
}

bool MAINMENU_loadButton(const CEGUI::EventArgs&)
{
	// TODO: Do something
}

bool MAINMENU_endButton(const CEGUI::EventArgs&)
{
	exit(0);
}
