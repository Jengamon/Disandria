#ifndef F_CEGUI_SM_FALCONFUNCTOR_H
#define F_CEGUI_SM_FALCONFUNCTOR_H

#include <CEGUI/CEGUI.h>
#include <falcon/engine.h>
#include <string>

/*
	If you're from Ruby, you'll know why I want to use this.
	#define unless(x) if(!x)
*/

class FalconFunctor
{
public:
    FalconFunctor(Falcon::VMachine*, CEGUI::String&);
    FalconFunctor(const FalconFunctor&);
    bool operator()(const CEGUI::EventArgs& args) const;
    bool clear_vm_after_usage;
    ~FalconFunctor();
private:
	Falcon::VMachine* d_vm;
	CEGUI::String d_function_name;
};

#endif // F_CEGUI_SM_FALCONFUNCTOR_H
