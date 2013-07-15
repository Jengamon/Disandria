#include "MainGameState.h"
#include "../MapParser.h"
#include "../GameManager.h"
#include "../StateManager.h"

void cleanup(thor::ActionContext<std::string>)
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
	window->addActionCallback("exit_game", thor::Action(sf::Keyboard::Q, thor::Action::PressOnce), cleanup);
}

void MainGameState::onRender(RenderWindow*)
{
}

void MainGameState::onCleanup(RenderWindow* window)
{
	setCurrentMap("");
	GameManager::getRenderWindow()->resetView();
	window->removeActionCallback("exit_game");
}
