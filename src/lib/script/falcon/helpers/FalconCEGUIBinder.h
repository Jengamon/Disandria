#ifndef FALCON_FALCONCEGUIBINDER_H
#define FALCON_FALCONCEGUIBINDER_H

#include <string>
#include <falcon/engine.h>
#include <CEGUI/CEGUI.h>

class FalconCEGUIBinder
{
public:
    FalconCEGUIBinder(Falcon::VMachine*, std::string);
    bool operator()(const CEGUI::EventArgs&);
private:
    Falcon::VMachine* cvm;
    Falcon::GarbageLock* lck;
};


#endif // FALCON_FALCONCEGUIBINDER_H
