#include "Image.h"

using namespace pugitmx;

std::string Image::getSourceString() const
{
    return source;
}

unsigned int Image::getWidth() const
{
    return width;
}

unsigned int Image::getHeight() const
{
    return height;
}

std::string Image::getTrans() const
{
    return trans;
}
