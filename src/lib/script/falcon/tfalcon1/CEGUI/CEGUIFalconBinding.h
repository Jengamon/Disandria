#ifndef __DISANDRIA_CEGUIFALCONBINDING_H
#define __DISANDRIA_CEGUIFALCONBINDING_H

#include <falcon/engine.h>
#include <CEGUI/CEGUI.h>

class CEGUIFalconBinding
{
public:
    static void addConstants(Falcon::Module*);
    static void addMethods(Falcon::Module*);
    static void addClasses(Falcon::Module*);
    static void addSingletons(Falcon::Module*);
    static Falcon::Module* createBinding();
private:
    static Falcon::Module* module;
};

#endif // __DISANDRIA_CEGUIFALCONBINDING_H