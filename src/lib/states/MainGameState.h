#ifndef MAINGAMESTATE_H
#define MAINGAMESTATE_H

#include "../StateBase.h"

class MainGameState : public StateBase
{
	private:
		std::string name();
		bool onInit(RenderWindow*);
		void onRender(RenderWindow*);
		void onCleanup(RenderWindow*);
};

#endif // MAINGAMESTATE_H
