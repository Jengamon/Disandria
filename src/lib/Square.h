#ifndef SQUARE_H
#define SQUARE_H

/*
 * Square.h
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



namespace disandria
{
struct Square {
    double tl;
    double tr;
    double bl;
    double br;
    static Square createSquare(double topl, double width, double height) {
        Square squ;
        squ.tl = topl;
        squ.tr = topl + width;
        squ.bl = topl + height;
        squ.br = topl + width + height;
        return squ;
    }
    static Square createSquare(double points[]) {
        Square squ;
        squ.tl = points[0];
        squ.tr = points[1];
        squ.bl = points[2];
        squ.br = points[3];
        return squ;
    }
    static Square createSquare(Square& squr) {
        Square squ;
        squ.tl = squr.tl;
        squ.tr = squr.tr;
        squ.bl = squr.bl;
        squ.br = squr.br;
        return squ;
    }
private:
    Square();
};
};

#endif // SQUARE_H
