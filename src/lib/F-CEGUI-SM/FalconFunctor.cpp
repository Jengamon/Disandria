#include "FalconFunctor.h"

FalconFunctor::FalconFunctor(Falcon::VMachine* vm, CEGUI::String& func) : d_vm(vm), d_function_name(func), clear_vm_after_usage(false) {}

FalconFunctor::FalconFunctor(const FalconFunctor& cpy)
{
	d_vm = cpy.d_vm;
	d_function_name = cpy.d_function_name;
	clear_vm_after_usage = false;
}

FalconFunctor::~FalconFunctor()
{
	if(clear_vm_after_usage)
	{
		d_vm->finalize();
	}
}

bool FalconFunctor::operator()(const CEGUI::EventArgs& args) const
{
	return true;
}
