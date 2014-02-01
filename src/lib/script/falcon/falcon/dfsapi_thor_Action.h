#ifndef __DISANDRIA_DFSAPI_THOR_ACTION_H
#define __DISANDRIA_DFSAPI_THOR_ACTION_H

#include <memory>
#include <Thor/Input.hpp>
#include <falcon/engine.h>

class dfsapi_thor_Action : public Falcon::CoreObject
{
public:
    static void init(Falcon::VMachine*);
    static Falcon::CoreObject* factory(const Falcon::CoreClass*, void*, bool);

    dfsapi_thor_Action(const Falcon::CoreClass*, thor::Action*);
    dfsapi_thor_Action(const Falcon::CoreClass*, thor::Action);
    dfsapi_thor_Action(const dfsapi_thor_Action&);

    virtual Falcon::CoreObject* clone() const;
    virtual bool setProperty(const Falcon::String&, const Falcon::Item&);
    virtual bool getProperty(const Falcon::String&, Falcon::Item&) const;

    const std::shared_ptr<thor::Action>& action() const {
        return act;
    }
    std::shared_ptr<thor::Action>& action() {
        return act;
    }
    const std::shared_ptr<thor::Action>& actionnref() const {
        return act;
    }
    std::shared_ptr<thor::Action>& actionnref() {
        return act;
    }

    static FALCON_FUNC combineAnd(Falcon::VMachine*);
    static FALCON_FUNC combineOr(Falcon::VMachine*);
private:
    std::shared_ptr<thor::Action> act;
};

#endif // __DISANDRIA_DFSAPI_THOR_ACTION_H
