#include "MainGameState.h"
#include "../Map.h"
#include "../MapManager.h"
#include "../GameManager.h"
#include "../StateManager.h"

std::string MainGameState::name()
{
    return "GAME";
}

bool MainGameState::onInit(RenderWindow* window)
{
    MapManager::setMap(new Map("testmap"));
    window->addActionCallback("exit_game", thor::Action(sf::Keyboard::Q, thor::Action::Hold), [](thor::ActionContext<std::string> context) {
        StateManager::setCurrentState(disandria::States::MAINMENU);
    });
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
