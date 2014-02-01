#include "cfsapi_functions.h"
#include <CEGUI/CEGUI.h>
#include <Poco/Foundation.h>
#include "lib/RenderWindowManager.h"

FALCON_FUNC renderLayout(Falcon::VMachine* vm)
{
    RenderWindow* win = RenderWindowManager::getRenderWindow("ROOT");
    Falcon::Item* loc = vm->param(0);
    if(loc == NULL || !loc->isString()) {
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("S"));
    }

    std::string rloc = Falcon::AutoCString(loc->asString()).c_str();
    poco_assert(win != NULL);
    win->displayWindow(win->renderLayout(rloc));
    vm->retnil();
}
