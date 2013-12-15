#ifndef __DISANDRIA_EFFECTTAGBASE_H
#define __DISANDRIA_EFFECTTAGBASE_H

#include <string>
/**
 * Use for generic pointer.
 */
class EffectTag
{
	public:
		virtual std::string id() = 0;
};

/**
 * Use for making new EffectTags
 * Correct usage:
 * 	class BlahBlahBlah : public EffectTagBase<int>
 * Means this class returns an int.
 */
template<typename T>
class EffectTagBase : public EffectTag
{
	public:
		virtual T getValue() = 0;
};

#endif // __DISANDRIA_EFFECTTAGBASE_H
