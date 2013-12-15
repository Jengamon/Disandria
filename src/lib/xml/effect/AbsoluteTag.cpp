#include "AbsoluteTag.h"

AbsoluteTag::AbsoluteTag(double val)
{
	value = val;
}

std::string AbsoluteTag::id()
{
	return "ABSOLUTE";
}

double AbsoluteTag::getValue()
{
	return value;
}
