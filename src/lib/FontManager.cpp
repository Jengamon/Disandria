#include "FontManager.h"
#include "GameManager.h"
#include "../helplib/Log.h"

std::string FontManager::defaultFont;

sf::Font* FontManager::createDefaultFont()
{
    static sf::Font* font = NULL;
    static std::string lastDefaultFont = "";

    if(font == NULL || lastDefaultFont != defaultFont) {
        if(font != NULL)
            delete font;

        font = new sf::Font;
        if(!font->loadFromFile(GameManager::getGameFolderName() + "fonts/" + defaultFont))
            Log::log("Failed to load default game font: " + defaultFont);

        lastDefaultFont = defaultFont;
    }

    return font;
}

void FontManager::setDefaultFont(std::string df)
{
    defaultFont = df;
}
