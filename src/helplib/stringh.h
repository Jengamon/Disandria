#ifndef __STRINGH_H_
#define __STRINGH_H_

#include <string>
#include <sstream>
#include <iomanip>

template<class N>
class String
{
public:
    static std::string toString(N a) {
        std::stringstream n;
        n << a;
        return n.str();
    }

    static N toElse(std::string a) {
        std::stringstream n;
        n << a;
        N x;
        n >> x;
        return x;
    }
};

class NString
{
public:
    static int fromHex(std::string a) {
        std::stringstream str;
        int ret;
        str << a;
        str >> std::hex >> ret;
        return ret;
    }

    static int fromOctal(std::string a) {
        std::stringstream str;
        int ret;
        str << a;
        str >> std::oct >> ret;
        return ret;
    }

    static int fromDecimal(std::string a) {
        std::stringstream str;
        int ret;
        str << a;
        str >> std::dec >> ret;
        return ret;
    }
};

class BString
{
public:
    static bool fromStringText(std::string a) {
        std::stringstream str;
        bool x;
        str << a;
        str >> std::boolalpha >> x;
        return x;
    }
};

#endif // __STRINGH_H_
