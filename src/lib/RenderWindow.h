#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/OpenGL/GLRenderer.h>
#include "../helplib/stringh.h"

class RenderWindow
{
	public:
		RenderWindow(int,int,std::string);
		sf::Vector2u getSize();
		sf::View getWindowView();
		sf::View getDefaultWindowView();
		void setWindowView(sf::View);
		void resetView();
		void startRendering();
		void render(sf::Sprite&, sf::Shader* = NULL);
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
		virtual ~RenderWindow();
	private:
		sf::RenderWindow* window;
		sf::Clock* elapsedclock;
};
	
#endif // RENDERWINDOW_H
