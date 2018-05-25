
#include <StepAction.hh>
#include <RunAction.hh>
#include <EventAction.hh>
#include "../include/ActionInit.hh"

ActionInit::ActionInit() {
//scoring = new Scoring();
}

ActionInit::~ActionInit()
{ }

void ActionInit::Build() const
{
auto runAction = new RunAction;
auto eventAction = new EventAction(runAction);
    SetUserAction(new PrimaryGen());

SetUserAction(new StepAction(eventAction));


    SetUserAction(runAction);
    SetUserAction(eventAction);
}