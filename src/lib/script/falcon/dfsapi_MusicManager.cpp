#include "dfsapi_MusicManager.h"
#include "../../MusicManager.h"
#include "dfsapi_sf_Music.h"

FALCON_FUNC dfsapi_MusicManager_createMusic(Falcon::VMachine* vm)
{
    Falcon::Item* name = vm->param(0);
    Falcon::Item* path = vm->param(1);
    if((name == NULL || !name->isString()) ||
            (path == NULL || !path->isString())) {
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("String, String"));
    }
    Falcon::AutoCString cname(*name);
    Falcon::AutoCString cpath(*path);

    sf::Music* msc = MusicManager::createMusic(cname.c_str(), cpath.c_str());
    Falcon::Item* mscC = vm->findWKI("sfMusic");
    Falcon::CoreClass* mscClass = mscC->asClass();
    dfsapi_sf_Music* fmsc = new dfsapi_sf_Music(mscClass, msc);
    vm->retval(fmsc);
}
