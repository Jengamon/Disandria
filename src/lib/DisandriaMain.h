#ifndef DISANDRIA__MAIN
#define DISANDRIA__MAIN

#include <Poco/Foundation.h>
#include <Poco/Util/XMLConfiguration.h>
#include "RenderWindow.h"
#include "GameManager.h"
#include "MusicManager.h"
#include "MenuManager.h"
#include "ImageManager.h"
#include "StatesManager.h"
#include "MapManager.h"
#include "FontManager.h"
#include "GameTimer.h"
#include "script/FalconSAPI.h"

class Disandria
{
	public:
		bool onInit();
		int run();
	private:
		int onCleanup();
		RenderWindow* rwin;
		FalconSAPI* sengine;
		Poco::AutoPtr<Poco::Util::XMLConfiguration> xmlConf;
};

#endif // DISANDRIA__MAIN
