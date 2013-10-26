#ifndef SCRIPT_FALCON_FSTRINGH_H
#define SCRIPT_FALCON_FSTRINGH_H

#include <falcon/engine.h>

class FString
{
public:
    static Falcon::String fromString(std::string str) {
        Falcon::String xan;
        xan.fromUTF8(str.c_str());
        return xan;
    }

    static std::string fromFalconString(Falcon::String* str) {
        std::string xan;
        Falcon::AutoCString cstr(str);
        xan = cstr.c_str();
        return xan;
    }
};

#endif // SCRIPT_FALCON_FSTRINGH_H
