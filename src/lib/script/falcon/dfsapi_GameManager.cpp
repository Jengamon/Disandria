#include "dfsapi_GameManager.h"
#include "../../GameManager.h"

FALCON_FUNC dfsapi_GameManager_getGameFolderName(Falcon::VMachine* vm)
{
	vm->retval(Falcon::String(GameManager::getGameFolderName().c_str()));
}

FALCON_FUNC dfsapi_GameManager_getEngineVersion(Falcon::VMachine* vm)
{
	vm->retval(GameManager::getEngineVersion());
}
