#include "FalconInterpreter.h"
#include <iostream>

bool FalconInterpreter::operator() (const CEGUI::EventArgs& args) const
{
	const CEGUI::WindowEventArgs* argument = dynamic_cast<const CEGUI::WindowEventArgs*>(&args);
	if(ffunc != NULL)
	{
		vm->pushParam(3);
		vm->callItem(*ffunc, 1);
		vm->reset();
		Falcon::Item& ret = vm->regA();
		return ret.isBoolean() ? ret.asBoolean() : true;
	}
	else
	{
		CEGUI_THROW(CEGUI::ScriptException("Unable to call non-existant Falcon event handler"));
	}
}
