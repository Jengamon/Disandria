#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>

class FontManager
{
public:
    static sf::Font* createDefaultFont();
    static void setDefaultFont(std::string);
private:
    static std::string defaultFont;
};

#endif // FONTMANAGER_H
