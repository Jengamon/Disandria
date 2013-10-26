#ifndef MAINMENU_STATES_H
#define MAINMENU_STATES_H

#include "../StateBase.h"

class MainMenuState : public StateBase
{
private:
    std::string name();
    bool onInit(RenderWindow*);
    void onRender(RenderWindow*);
    void onCleanup(RenderWindow*);
};

#endif // MAINMENU_STATES_H
