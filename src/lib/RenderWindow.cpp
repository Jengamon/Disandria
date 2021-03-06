#include "RenderWindow.h"
#include "GameManager.h"
#ifdef FALCON1
#else
#include "script/falcon/falcon/CEGUI/FalconScriptingModule.h"
#endif

RenderWindow::RenderWindow(int width, int height, std::string name) : sf::RenderWindow(sf::VideoMode(width, height), name, sf::Style::Close | sf::Style::Titlebar)
{
    elapsedclock = new sf::Clock;
    inpMan = new InputManager;
    glEnable(GL_TEXTURE_2D);

    CEGUI::OpenGLRenderer& renderer = CEGUI::OpenGLRenderer::bootstrapSystem();
    CEGUI::DefaultResourceProvider* rp = static_cast<CEGUI::DefaultResourceProvider*>(CEGUI::System::getSingleton().getResourceProvider());

    rp->setResourceGroupDirectory("schemes", GameManager::getGameFolderName() + "gui/schemes/");
    rp->setResourceGroupDirectory("imagesets", GameManager::getGameFolderName() + "gui/imagesets/");
    rp->setResourceGroupDirectory("fonts", GameManager::getGameFolderName() + "gui/fonts/");
    rp->setResourceGroupDirectory("layouts", GameManager::getGameFolderName() + "gui/layouts/");
    rp->setResourceGroupDirectory("looknfeels", GameManager::getGameFolderName() + "gui/looknfeel/");
    rp->setResourceGroupDirectory("lua_scripts", GameManager::getGameFolderName() + "gui/lua_scripts/");
    rp->setResourceGroupDirectory("falcon_scripts", GameManager::getGameFolderName() + "gui/falcon_scripts/");
    rp->setResourceGroupDirectory("schemas", GameManager::getGameFolderName() + "gui/xml_schemas/");

    CEGUI::ImageManager::setImagesetDefaultResourceGroup("imagesets");
    CEGUI::Font::setDefaultResourceGroup("fonts");
    CEGUI::Scheme::setDefaultResourceGroup("schemes");
    CEGUI::WidgetLookManager::setDefaultResourceGroup("looknfeels");
    CEGUI::WindowManager::setDefaultResourceGroup("layouts");
    CEGUI::ScriptModule::setDefaultResourceGroup("falcon_scripts");

    CEGUI::XMLParser* parser = CEGUI::System::getSingleton().getXMLParser();
    if(parser->isPropertyPresent("SchemaDefaultResourceGroup"))
        parser->setProperty("SchemaDefaultResourceGroup", "schemas");

#ifdef FALCON1
#else
    CEGUI::System::getSingleton().setScriptingModule(FalconScriptingModule::create());
#endif
    CEGUI::System::getSingleton().executeScriptFile("gui", "falcon_scripts");

    this->setVerticalSyncEnabled(true);
    this->setFramerateLimit(60);

    // Remove and put to script ASAP
    loadScheme("TaharezLook");
    loadFont("Inconsolata-14");
    setArrowandTooltipScheme("TaharezLook");
    // --END--
    setupMap();
}

void RenderWindow::resetView()
{
    sf::View dview = this->getDefaultView();
    this->setView(dview);
}

void RenderWindow::startRendering()
{
    this->pushGLStates();
}

void RenderWindow::renderGUI()
{
    this->popGLStates();
    CEGUI::System::getSingleton().renderAllGUIContexts();
}

CEGUI::Window* RenderWindow::renderLayout(std::string lyout)
{
    return CEGUI::WindowManager::getSingleton().loadLayoutFromFile(lyout);
}

void RenderWindow::displayWindow(CEGUI::Window* win)
{
    CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(win);
}
#include <iostream>
void RenderWindow::handleEvent(sf::Event& event)
{
    actionMap.pushEvent(event);
    if(actionMap.isActive("QUIT"))
        this->close();

    actionMap.invokeCallbacks(callbackSystem, this);

    CEGUI::GUIContext& context = CEGUI::System::getSingleton().getDefaultGUIContext();
    sf::Vector2i mousep = sf::Mouse::getPosition(*this);
    if(event.type == sf::Event::MouseLeft)
        context.injectMouseLeaves();
    context.injectMousePosition(mousep.x, mousep.y);
    if(event.type == sf::Event::MouseButtonPressed)
        context.injectMouseButtonDown(CEGUI::MouseButton(event.mouseButton.button));
    if(event.type == sf::Event::MouseButtonReleased)
        context.injectMouseButtonUp(CEGUI::MouseButton(event.mouseButton.button));
    if(event.type == sf::Event::KeyPressed)
        context.injectKeyDown(convertKey(event.key.code));
    if(event.type == sf::Event::KeyReleased)
        context.injectKeyUp(convertKey(event.key.code));
    if(event.type == sf::Event::TextEntered)
        context.injectChar(event.text.unicode);
    if(event.type == sf::Event::MouseWheelMoved)
        context.injectMouseWheelChange(event.mouseWheel.delta);
    float elapsedTime = elapsedclock->restart().asSeconds();
    CEGUI::System::getSingleton().injectTimePulse(elapsedTime);
    context.injectTimePulse(elapsedTime);
    actionMap.clearEvents();
}

RenderWindow::~RenderWindow()
{
    CEGUI::OpenGLRenderer::destroySystem();
    delete elapsedclock;
    delete inpMan;
    elapsedclock = NULL;
}

void RenderWindow::clearWindow()
{
    this->clear(sf::Color::Black);
}

void RenderWindow::loadScheme(std::string str)
{
    CEGUI::SchemeManager::getSingleton().createFromFile((str + ".scheme").c_str());
}

void RenderWindow::loadFont(std::string str)
{
    CEGUI::FontManager::getSingleton().createFromFile((str + ".font").c_str());
}

void RenderWindow::setArrowandTooltipScheme(std::string str)
{
    setArrowScheme(str);
    setTooltipScheme(str);
}

void RenderWindow::setArrowScheme(std::string str)
{
    CEGUI::System::getSingleton().getDefaultGUIContext().getMouseCursor().setDefaultImage((str + "/MouseArrow").c_str());
}

void RenderWindow::setTooltipScheme(std::string str)
{
    CEGUI::System::getSingleton().getDefaultGUIContext().setDefaultTooltipType((str + "/Tooltip").c_str());
}
