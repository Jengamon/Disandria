#include "Scene.h"
#include "../helplib/Log.h"

void Scene::addImage(sf::Sprite spr)
{
    imageList.push_back(spr);
}

void Scene::setShader(sf::Shader* shd)
{
    currentShader = shd;
}

void Scene::clearList()
{
    for(std::list<ImageSpec>::iterator iter = imageList.begin(); iter != imageList.end(); iter++) {
        delete iter->imagePointer;
    }
    imageList.clear();
}

void Scene::deleteShader()
{
    if(currentShader != NULL) {
        delete currentShader;
        currentShader = NULL;
    }
}

void Scene::addSubScene(Scene* scene)
{
    sceneList.push_back(scene);
}

sf::Image* Scene::render()
{
    sf::Image* sceneImage = new sf::Image;
    sceneImage->create(width, height);
    for(std::list<ImageSpec>::iterator iter = imageList.begin(); iter != imageList.end(); iter++) {
        if(iter->imagePointer != NULL) {
            sceneImage->copy(*iter->imagePointer, iter->x, iter->y);
        }
    }
    for(std::list<Scene*>::iterator iter = sceneList.begin(); iter != sceneList.end(); iter++) {
        if(*iter != NULL) {
            sceneImage->copy(*(*iter)->render(), 0, 0);
        }
    }
}
