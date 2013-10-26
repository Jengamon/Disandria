#include "MainGameState.h"
#include "../Map.h"
#include "../MapManager.h"
#include "../GameManager.h"
#include "../StateManager.h"

void cleanup(thor::ActionContext<std::string> context)
{
    StateManager::setCurrentState(disandria::States::MAINMENU);
}

std::string MainGameState::name()
{
    return "GAME";
}

bool MainGameState::onInit(RenderWindow* window)
{
    MapManager::setMap(new Map("testmap"));
    window->addActionCallback("exit_game", thor::Action(sf::Keyboard::Q, thor::Action::Hold), cleanup);
}

void MainGameState::onRender(RenderWindow*)
{
}

void MainGameState::onCleanup(RenderWindow* window)
{
    GameManager::getRenderWindow()->resetView();
    MapManager::clearMap();
    window->removeActionCallback("exit_game");
}
