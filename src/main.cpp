#include "lib/DisandriaApp.h"
#include "lib/WindowSubsystem.h"

int main(int argc, char* argv[])
{
    DisandriaApp app;
    app.addSubsystem(new WindowSubsystem);
    app.init(argc, argv);
    return app.run();
}
