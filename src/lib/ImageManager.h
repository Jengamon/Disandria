#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

/*
 * ImageManager.h
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
#include <map>
#include "RenderWindow.h"

namespace disandria
{
struct Image {
    sf::Texture* tex;
    int renderFrames;
    static Image createImage(sf::Texture* tex, int rf) {
        Image im;
        im.tex = tex;
        im.renderFrames = rf;
        return im;
    }
};
struct InternalImage {
    sf::Sprite spr;
    int renderFrames;
};
};

class ImageManager
{
public:
    static void setRenderWindow(RenderWindow*);
    static void renderImage(std::string, disandria::Image);
    static void renders();
    static sf::Sprite* getImage(std::string);
    static void deleteImage(std::string);
private:
    static RenderWindow* rwindow;
    static std::map<std::string, disandria::InternalImage> images;
};

#endif // IMAGEMANAGER_H
