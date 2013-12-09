#include "lib/DisandriaApp.h"
#include "lib/WindowSubsystem.h"
#include "lib/ScriptSubsystem.h"

int main(int argc, char* argv[])
{
    DisandriaApp app;
	app.addSubsystem(new WindowSubsystem);
    app.addSubsystem(new ScriptSubsystem);
    app.init(argc, argv);
    return app.run();
}
