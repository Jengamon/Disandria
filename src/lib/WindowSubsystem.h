#ifndef __DISANDRIA_WINDOWSUBSYSTEM_H
#define __DISANDRIA_WINDOWSUBSYSTEM_H

/*
 * WindowSubsystem.h
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



#include <Poco/Util/Subsystem.h>
#include "RenderWindow.h"

class WindowSubsystem : public Poco::Util::Subsystem
{
    /**
     * @brief Initialize the WindowSubsystem
     * @param app Application to initialize
     *
     * Initializes the WindowSubsystem of Disandria
     */
    void initialize(Poco::Util::Application& app);

    /**
     * @brief Uninitialize the WindowSubsystem
     *
     * Uninitialize the WindowSubsystem. Performs any required cleanup.
     */
    void uninitialize();

    /**
     * @brief Define command-line options for the WindowSubsystem
     * @param opst OptionSet to write options to
     *
     * Make command-line control of the WindowSubsystem possible
     */
    void defineOptions(Poco::Util::OptionSet& opst);

    /**
     * @brief Name of WindowSubsystem
     *
     * ...What do you expect?
     */
    const char* name() const;
};

#endif // __DISANDRIA_WINDOWSUBSYSTEM_H
