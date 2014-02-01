#ifndef STATES_H
#define STATES_H

/*
 * States.h
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



#include <Poco/Platform.h>

#ifdef POCO_OS_FAMILY_WINDOWS
#undef VOID
#endif

namespace disandria
{
namespace States
{
enum State {
    VOID,
    MAINMENU,
    MAINGAME
};
};
};

#endif // STATES_H
