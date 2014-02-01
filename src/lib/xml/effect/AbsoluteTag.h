#ifndef __DISANDRIA_ABSOLUTETAG_H
#define __DISANDRIA_ABSOLUTETAG_H

#include "EffectTagBase.h"
class AbsoluteTag : public EffectTagBase<double>
{
public:
    AbsoluteTag(double);
    std::string id();
    double getValue();
private:
    double value;
};

#endif // __DISANDRIA_ABSOLUTETAG_H
