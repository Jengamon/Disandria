#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <Thor/Graphics.hpp>
#include <Thor/Input.hpp>
#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/OpenGL/GLRenderer.h>
#include "../helplib/stringh.h"

namespace thor
{
	typedef void(*ActionCallback)(thor::ActionContext<std::string>);
}

class RenderWindow
{
	public:
		RenderWindow(int,int,std::string);
		sf::Vector2u getSize();
		sf::View getWindowView();
		sf::View getDefaultWindowView();
		void addActionCallback(std::string, thor::Action, thor::ActionCallback);
		void removeActionCallback(std::string);
		void removeAllActionCallbacks();
		void setWindowView(sf::View);
		void resetView();
		void startRendering();
		void render(sf::Sprite&, sf::Shader* = NULL);
		void render(sf::Text&, sf::Shader* = NULL);
		void render(thor::BigSprite&, sf::Shader* = NULL);
		void renderGUI();
		CEGUI::Window* renderLayout(std::string);
		void displayWindow(CEGUI::Window*);
		void clear();
		bool isOpen();
		bool pollEvent(sf::Event&);
		void handleEvent(sf::Event&);
		CEGUI::Key::Scan convertKey(sf::Keyboard::Key&);
		void loadScheme(std::string);
		void loadFont(std::string);
		void setArrowandTooltipScheme(std::string);
		void setArrowScheme(std::string);
		void setTooltipScheme(std::string);
		void display();
		void close();
		virtual ~RenderWindow();
	private:
		void setupMap();
		thor::ActionMap<std::string> actionMap;
		thor::ActionMap<std::string>::CallbackSystem callbackSystem;
		sf::RenderWindow* window;
		sf::Clock* elapsedclock;
};
	
#endif // RENDERWINDOW_H
