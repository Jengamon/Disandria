#include "GameTimer.h"

thor::CallbackTimer GameTimer::timer;

void GameTimer::setTimer(int dbl)
{
	timer.reset(sf::seconds(dbl));	
}

void GameTimer::addListener(thor::CallbackTimer::Listener listen)
{
	timer.connect(listen);
}

void GameTimer::reset()
{
	timer.clearConnections();
}

void GameTimer::update()
{
	timer.update();
}

void GameTimer::start()
{
	timer.start();
}

void GameTimer::stop()
{
	timer.stop();
}

bool GameTimer::isRunning()
{
	return timer.isRunning();
}

bool GameTimer::isExpired()
{
	return timer.isExpired();
}

double GameTimer::getRemainingTime()
{
	return timer.getRemainingTime().asSeconds();
}

void GameTimer::renderTime(RenderWindow* window)
{
	sf::Text time;
	time.setFont(*FontManager::createDefaultFont());
	double tim = getRemainingTime();
	int minutes = int(tim) / 60;
	int seconds = int(tim) % 60;
	if((seconds / 10) >= 1)
		time.setString(String<int>::toString(minutes) + ":" + String<int>::toString(seconds));
	else
		time.setString(String<int>::toString(minutes) + ":0" + String<int>::toString(seconds));

	#define DIV_CONSTANT 50
	int window_x = window->getSize().x / DIV_CONSTANT;
	int window_y = window->getSize().y / DIV_CONSTANT;
	#undef DIV_CONSTANT
	time.setPosition(window_x, window_y);
	window->draw(time);
}
