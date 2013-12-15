#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

/*
 * RenderWindow.h
 * This file is part of Disandria
 *
 * Copyright (C) 2013 - Bob Hostern
 *
 * Disandria is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Disandria is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Disandria. If not, see <http://www.gnu.org/licenses/>.
 */



#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <Thor/Graphics.hpp>
#include <Thor/Input.hpp>
#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/OpenGL/GLRenderer.h>
#include "InputManager.h"
#include "../helplib/stringh.h"

/**
 * @todo Stop looking at this and write the documentation!
 * @todo Change from a direct rendering model to a Screen-based model.
 */
class RenderWindow : public sf::RenderWindow
{
public:
	/**
	 * @brief Creates a RenderWindow
	 * @pre Make sure you haven't created another RenderWindow, as only
	 * one window at a time is supported by CEGUI, the underlying GUI library
	 * for Disandria.
	 * @param wd Width of RenderWindow
	 * @param ht Height of RenderWindow
	 * @param nm Name of RenderWindow (on the titlebar)
	 * 
	 * Creates a RenderWindow, the mastermind of rendering in Disandria.
	 */
    RenderWindow(int wd, int ht, std::string nm);
    
    /**
     * @brief Start rendering
     * 
     * Due to the nuances of using CEGUI with SFML, this must be called BEFORE any rendering
     * is done, or else CEGUI will clear your display, and replace it with the GUI.
     */
    void startRendering();
    
    /**
     * @brief Render GUI
     * @pre Must have called startRendering()
     * 
     * Renders the GUI using CEGUI. If you drew anything without using startRendering()...
     * It may be safe for a spell, but you'll run out of memory sooner or later.
     */
    void renderGUI();
    
    /**
     * @brief Render a CEGUI .layout file
     * 
     * Renders a .layout file as a CEGUI::Window pointer.
     */
    CEGUI::Window* renderLayout(std::string);
    
    /**
     * @brief Set a CEGUI::Window, as root GUI window
     * 
     * Despite the name, it does not change the window itself; it just sets the root element
     * of the GUI as the window that is passed in. Used in combination with renderLayout()
     * to load a .layout and display it.
     * 
     * Example:
     * @code
     * RenderWindow x(200, 100, "TestWindow");
     * x->displayWindow(x->renderLayout("mina.layout"));
     * @endcode
     */
    void displayWindow(CEGUI::Window*);
    
    /**
     * @brief Clears the window
     * 
     * Clears the window to a black color. Does not affect GUI.
     */
    void clearWindow();
    
    /**
     * @brief Resets View to default
     * 
     * Resets the RenderWindow view to the default View.
     */
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
