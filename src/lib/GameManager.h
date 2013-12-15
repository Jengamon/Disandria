#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

/*
 * GameManager.h
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



#include "../helplib/stringh.h"
#include "RenderWindow.h"

class GameManager
{
public:
	/**
	 * @brief Set's the current game's name
	 * @param gn Game name
	 * 
	 * Sets the current game name.
	 */
    static void setGameName(std::string gn);
    
    /**
     * @brief Get path to game folder
     * @pre Must have set game's name
     * 
     * Gets the path to the main folder, the root of the Disandria project that is
     * currently being ran.
     */
    static std::string getGameFolderName();
    
    /**
     * @deprecated as most classes that use this function are to be removed, and will need to be scripted.
     * @brief Set the render window
     * @param rwnd RenderWindow to save to pointer
     * 
     * Saves a RenderWindow from a pointer.
     */
    static void setRenderWindow(RenderWindow* rwnd);
    
    /**
     * @deprecated as most classes that use this function are to be removed, and will need to be scripted.
     * @brief Get the render window
     * 
     * Gets the current saved RenderWindow.
     */
    static RenderWindow* getRenderWindow();
    
    /**
     * @brief Get Disandria version
     * 
     * Gets the current Disandria version.
     */
    static double getEngineVersion();
private:

	/**
	 * @brief Game name
	 * 
	 * Stores game name.
	 */
    static std::string gameName;
    
    /**
     * @deprecated as most classes that use this are to be removed, and will need to be scripted.
     * @brief Saved RenderWindow
     * 
     * RenderWindow saved by the use of setRenderWindow()
     */
    static RenderWindow* window;
};

#endif // GAMEMANAGER_H
