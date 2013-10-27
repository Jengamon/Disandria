#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <Thor/Graphics.hpp>
#include <Thor/Input.hpp>
#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/OpenGL/GLRenderer.h>
#include <CEGUI/ScriptingModules/LuaScriptModule/CEGUILua.h>
#include "InputManager.h"
#include "../helplib/stringh.h"

class RenderWindow : public sf::RenderWindow
{
public:
    RenderWindow(int, int, std::string);
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
    void addActionCallback(std::string evtnm, thor::Action act, thor::ActionCallback func);
    void removeActionCallback(std::string id);
    virtual ~RenderWindow();
private:
    sf::Clock* elapsedclock;
    InputManager* inpMan;
};

#endif // RENDERWINDOW_H
