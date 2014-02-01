#ifndef __DISANDRIA_OPERBASE_H
#define __DISANDRIA_OPERBASE_H

#include <queue>

template<typename T>
class OperBase
{
public:
    virtual void addChild(OperBase*);
    virtual int childCount();
    virtual T solve() = 0;
protected:
    std::queue<OperBase> children;
};

#endif // __DISANDRIA_OPERBASE_H