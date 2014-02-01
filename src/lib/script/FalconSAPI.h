#ifndef __DISANDRIA_REDIRECT_FALCONSAPI_H
#define __DISANDRIA_REDIRECT_FALCONSAPI_H

#ifdef FALCON1
#warning Using incomplete Falcon 1.0 SAPI module
#include "falcon/falcon1/FalconSAPI.h"
#else
#warning Using incomplete Falcon 0.9.6.8 SAPI module
#include "falcon/falcon/FalconSAPI.h"
#endif

#endif // __DISANDRIA_REDIRECT_FALCONSAPI_H
