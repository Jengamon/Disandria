#ifndef __DISANDRIA_DFSAPI_FUNCTIONS_H
#define __DISANDRIA_DFSAPI_FUNCTIONS_H

#include <falcon/engine.h>

/**
 * The engine usually handles script errors gracefully, continuing.
 * Use this function to exit immediately.
 */
FALCON_FUNC closeSystem(Falcon::VMachine*);

#endif // __DISANDRIA_DFSAPI_FUNCTIONS_H
