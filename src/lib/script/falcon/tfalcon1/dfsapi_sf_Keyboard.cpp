#include "dfsapi_sf_Keyboard.h"
#include <SFML/Window.hpp>

FALCON_FUNC dfsapi_sf_Keyboard_isKeyPressed(Falcon::VMachine* vm)
{
    Falcon::Item* key = vm->param(0);
    if(key == NULL || !key->isOrdinal()) {
        throw new Falcon::ParamError(Falcon::ErrorParam(Falcon::e_inv_params, __LINE__).extra("I"));
    }

    Falcon::int64 k = key->forceInteger();
    vm->retval(sf::Keyboard::isKeyPressed((sf::Keyboard::Key)k));
}
