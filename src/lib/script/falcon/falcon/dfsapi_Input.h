#ifndef __DISANDRIA_DFSAPI_INPUT_H
#define __DISANDRIA_DFSAPI_INPUT_H

#include "lib/RenderWindowManager.h"
#include "lib/RenderWindow.h"
#include <falcon/engine.h>

FALCON_FUNC dfsapi_Input_addAction(Falcon::VMachine*);
FALCON_FUNC dfsapi_Input_addCallback(Falcon::VMachine*);
FALCON_FUNC dfsapi_Input_addActionCallback(Falcon::VMachine*);
FALCON_FUNC dfsapi_Input_removeCallback(Falcon::VMachine*);
FALCON_FUNC dfsapi_Input_clearCallbacks(Falcon::VMachine*);

#endif // __DISANDRIA_DFSAPI_INPUT_H
