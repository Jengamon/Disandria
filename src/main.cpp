#include "lib/DisandriaMain.h"
#include "helplib/Log.h"

int main()
{
	Disandria main;
	if(!main.onInit())
	{
		Log::log("Disandria failed to initialize. Look above for reasons.");
	}
	return main.run();
}
