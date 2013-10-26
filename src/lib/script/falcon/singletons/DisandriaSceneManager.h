#ifndef FALCON_DISANDRIASCENEMANAGER_H
#define FALCON_DISANDRIASCENEMANAGER_H

#include <falcon/engine.h>
#include <map>
#include "../../../../helplib/stringh.h"
#include "../../../Scene.h"

class DisandriaSceneManager
{
public:
    static void createScene(Falcon::VMachine*);
    static void renderScene(Falcon::VMachine*);
    static void deleteScene(Falcon::VMachine*);
private:
    static std::map<std::string, Scene*> scenes;
};

#endif // FALCON_DISANDRIASCENEMANAGER_H
