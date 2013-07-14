#include "RenderWindow.h"
#include "GameManager.h"
RenderWindow::RenderWindow(int width, int height, std::string name)
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), name, sf::Style::Close | sf::Style::Titlebar);
	elapsedclock = new sf::Clock;
	glEnable(GL_TEXTURE_2D);
	CEGUI::OpenGLRenderer& renderer = CEGUI::OpenGLRenderer::bootstrapSystem();
	window->setVerticalSyncEnabled(true);
	window->setFramerateLimit(60);

	CEGUI::DefaultResourceProvider* rp = static_cast<CEGUI::DefaultResourceProvider*>(CEGUI::System::getSingleton().getResourceProvider());

	rp->setResourceGroupDirectory("schemes", GameManager::getGameFolderName() + "gui/schemes/");
	rp->setResourceGroupDirectory("imagesets", GameManager::getGameFolderName() + "gui/imagesets/");
	rp->setResourceGroupDirectory("fonts", GameManager::getGameFolderName() + "gui/fonts/");
	rp->setResourceGroupDirectory("layouts", GameManager::getGameFolderName() + "gui/layouts/");
	rp->setResourceGroupDirectory("looknfeels", GameManager::getGameFolderName() + "gui/looknfeel/");
	rp->setResourceGroupDirectory("lua_scripts", GameManager::getGameFolderName() + "gui/lua_scripts/");
	rp->setResourceGroupDirectory("schemas", GameManager::getGameFolderName() + "gui/xml_schemas/");

	CEGUI::ImageManager::setImagesetDefaultResourceGroup("imagesets");
	CEGUI::Font::setDefaultResourceGroup("fonts");
	CEGUI::Scheme::setDefaultResourceGroup("schemes");
	CEGUI::WidgetLookManager::setDefaultResourceGroup("looknfeels");
	CEGUI::WindowManager::setDefaultResourceGroup("layouts");
	CEGUI::ScriptModule::setDefaultResourceGroup("lua_scripts");

	CEGUI::XMLParser* parser = CEGUI::System::getSingleton().getXMLParser();
	if (parser->isPropertyPresent("SchemaDefaultResourceGroup"))
		parser->setProperty("SchemaDefaultResourceGroup", "schemas");

	loadScheme("TaharezLook");
	loadFont("DejaVuSans-14");
	setArrowandTooltipScheme("TaharezLook");
	setupMap();
}

sf::Vector2u RenderWindow::getSize()
{
	return window->getSize();
}

sf::View RenderWindow::getWindowView()
{
	return window->getView();
}

sf::View RenderWindow::getDefaultWindowView()
{
	return window->getDefaultView();
}

void RenderWindow::setWindowView(sf::View view)
{
	window->setView(view);
}

void RenderWindow::resetView()
{
	sf::View dview = window->getDefaultView();
	window->setView(dview);
}

void RenderWindow::startRendering()
{
	window->pushGLStates();
}

void RenderWindow::render(sf::Sprite& spr, sf::Shader* shd)
{
	window->draw(spr, shd);
}

void RenderWindow::render(thor::BigSprite& spr, sf::Shader* shd)
{
	window->draw(spr, shd);
}

void RenderWindow::display()
{
	window->display();
}

void RenderWindow::renderGUI()
{
	window->popGLStates();
	CEGUI::System::getSingleton().renderAllGUIContexts();
}

CEGUI::Window* RenderWindow::renderLayout(std::string lyout)
{
	return CEGUI::WindowManager::getSingleton().loadLayoutFromFile(lyout);
}

bool RenderWindow::isOpen()
{
	return window->isOpen();
}

void RenderWindow::displayWindow(CEGUI::Window* win)
{
	CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(win);
}

bool RenderWindow::pollEvent(sf::Event& event)
{
	return window->pollEvent(event);
}

void RenderWindow::setupMap()
{
	actionMap["quit"] = thor::Action(sf::Event::Closed) || thor::Action(sf::Keyboard::Escape, thor::Action::PressOnce);
}

void RenderWindow::addWindowCallback(std::string evtnm, thor::Action act, thor::ActionCallback func)
{
	actionMap[evtnm] = act;
	callbackSystem.connect(evtnm, func);
}

void RenderWindow::handleEvent(sf::Event& event)
{
	actionMap.pushEvent(event);
	if(actionMap.isActive("quit"))
		window->close();

	actionMap.invokeCallbacks(callbackSystem, window);

	CEGUI::GUIContext& context = CEGUI::System::getSingleton().getDefaultGUIContext();
	sf::Vector2i mousep = sf::Mouse::getPosition(*window);
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
}

RenderWindow::~RenderWindow()
{
	delete window;
	delete elapsedclock;
	window = NULL;
	elapsedclock = NULL;
}

void RenderWindow::clear()
{
	window->clear(sf::Color::Black);
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
