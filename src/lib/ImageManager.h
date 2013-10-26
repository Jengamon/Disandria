#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

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
