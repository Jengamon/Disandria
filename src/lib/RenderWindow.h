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

class RenderWindow : public sf::RenderWindow
{
	public:
		RenderWindow(int,int,std::string);
		void addActionCallback(std::string, thor::Action, thor::ActionCallback);
		void removeActionCallback(std::string);
		void removeAllActionCallbacks();
		void startRendering();
		void renderGUI();
		CEGUI::Window* renderLayout(std::string);
		void displayWindow(CEGUI::Window*);
		void clearWindow();
		void resetView();
		void handleEvent(sf::Event&);
		CEGUI::Key::Scan convertKey(sf::Keyboard::Key&);
		void loadScheme(std::string);
		void loadFont(std::string);
		void setArrowandTooltipScheme(std::string);
		void setArrowScheme(std::string);
		void setTooltipScheme(std::string);
		virtual ~RenderWindow();
	private:
		void setupMap();
		thor::ActionMap<std::string> actionMap;
		thor::ActionMap<std::string>::CallbackSystem callbackSystem;
		sf::Clock* elapsedclock;
};
	
#endif // RENDERWINDOW_H
