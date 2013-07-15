#include "MainGameState.h"
#include "../MapParser.h"
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

void MainGameState::setCurrentMap(std::string map)
{
	MapParser::loadCurrentMap(map);
}

bool MainGameState::onInit(RenderWindow* window)
{
	setCurrentMap("testmap");
	window->addActionCallback("exit_game", thor::Action(sf::Keyboard::Q, thor::Action::Hold), cleanup);
}

void MainGameState::onRender(RenderWindow*)
{
}

void MainGameState::onCleanup(RenderWindow* window)
{
	GameManager::getRenderWindow()->resetView();
	setCurrentMap("");
	window->removeActionCallback("exit_game");
}
