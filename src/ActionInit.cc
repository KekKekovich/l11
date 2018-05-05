
#include <StepAction.hh>
#include <RunAction.hh>
#include <EventAction.hh>
#include "../include/ActionInit.hh"

ActionInit::ActionInit()
{ scoring = new Scoring();}

ActionInit::~ActionInit()
{ }

void ActionInit::Build() const
{


    SetUserAction(new PrimaryGen());


}