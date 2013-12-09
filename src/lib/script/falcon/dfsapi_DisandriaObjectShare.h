#ifndef __DISANDRIA_DFSAPI_DISANDRIAOBJECTSHARE_H
#define __DISANDRIA_DFSAPI_DISANDRIAOBJECTSHARE_H

#include <string>
#include <map>
#include <falcon/engine.h>

class dfsapi_DisandriaObjectShare
{
	public:
		static FALCON_FUNC addObject(Falcon::VMachine*);
		static FALCON_FUNC getObject(Falcon::VMachine*);
		static FALCON_FUNC removeObject(Falcon::VMachine*);
		static FALCON_FUNC isObjectAvailable(Falcon::VMachine*);
	private:
		static std::map<std::string, Falcon::GarbageLock*> objectHolder;
};

#endif // __DISANDRIA_DFSAPI_DISANDRIAOBJECTSHARE_H