#include "OperBase.h"

template<typename T> void OperBase<T>::addChild(OperBase* ob)
{
    children.push_back(&ob);
}

template<typename T> int OperBase<T>::childCount()
{
    return children.size();
}