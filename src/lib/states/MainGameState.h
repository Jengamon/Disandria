#ifndef MAINGAMESTATE_H
#define MAINGAMESTATE_H

#include "../StateBase.h"

class MainGameState : public StateBase
{
	public:
		void setCurrentMap(std::string);
	private:
		std::string name();
		bool onInit(RenderWindow*);
		void onRender(RenderWindow*);
		void onCleanup(RenderWindow*);
};

#endif // MAINGAMESTATE_H
