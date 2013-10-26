#ifndef DISANDRIA_SCENE_H
#define DISANDRIA_SCENE_H

#include <string>
#include <list>
#include <SFML/Graphics.hpp>
#include <Thor/Graphics.hpp>
#include "RenderWindow.h"

struct ImageSpec {
    ImageSpec(unsigned int _x, unsigned int _y, sf::Image* img = NULL) : x(_x), y(_y), imagePointer(img) {}
    sf::Image* imagePointer;
    unsigned int x;
    unsigned int y;
};

class Scene
{
public:
    Scene(std::string ident, unsigned int _width, unsigned int _height) : identifier(ident), width(_width), height(_height) {}
    void addImage(ImageSpec spec);
    void setShader(sf::Shader*);
    void deleteShader();
    void clearList();
    void addSubScene(Scene* scene);
    sf::Image* render();
private:
    unsigned int width;
    unsigned int height;
    std::string identifier;
    std::list<ImageSpec> imageList;
    std::list<Scene*> sceneList;
    sf::Shader* currentShader;
};

#endif // DISANDRIA_SCENE_H
