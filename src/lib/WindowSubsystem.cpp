#include "WindowSubsystem.h"
#include "MapManager.h"
#include "ImageManager.h"
#include "GameManager.h"
#include "RenderWindowManager.h"
#include <Poco/Util/Application.h>
using namespace Poco::Util;

void WindowSubsystem::initialize(Application& app)
{
    int width = app.config().getInt("project.sys.width", 0);
    int height = app.config().getInt("project.sys.height", 0);

    if(width == 0) {
        width = app.config().getInt("project.window.width", 0);
        if(width == 0)
            app.logger().error("Invalid window width.");
    }

    if(height == 0) {
        height = app.config().getInt("project.window.height", 0);
        if(height == 0)
            app.logger().error("Invalid window height.");
    }
	
    if(RenderWindowManager::registerRenderWindow(0, RenderWindowManager::Params::createParam(width, height, app.config().getString("project.name")))) {
        if(!RenderWindowManager::linkRegisterToString("ROOT", 0)) {
            app.logger().error("Root window could not be set to ROOT.");
            exit(-1);
        }
    } else {
        app.logger().error("Root window could not be created.");
        exit(-1);
    }
    
    RenderWindow* rwin = RenderWindowManager::getRenderWindow("ROOT");

    GameManager::setRenderWindow(rwin);
    ImageManager::setRenderWindow(rwin);
    MapManager::setRenderWindow(rwin);
}

void WindowSubsystem::uninitialize()
{
    RenderWindowManager::cleanupRenderWindow("ROOT");
    GameManager::setRenderWindow(NULL);
    ImageManager::setRenderWindow(NULL);
    MapManager::setRenderWindow(NULL);
}

void WindowSubsystem::defineOptions(OptionSet& opst)
{
    opst.addOption(
        Option("width", "w", "Set window width")
        .required(false)
        .argument("size")
        .repeatable(false)
        .group("windowwidth")
        .binding("project.sys.width"));

    opst.addOption(
        Option("height", "t", "Set window height (\"tall\"ness)")
        .required(false)
        .argument("size")
        .repeatable(false)
        .group("windowheight")
        .binding("project.sys.height"));
}

const char* WindowSubsystem::name() const
{
    return "Disandria WindowSubsystem";
}
