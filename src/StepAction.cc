//
// Created by student on 14.04.18.
//

#include <EventAction.hh>
#include <G4Step.hh>
#include <G4UserSteppingAction.hh>
#include <StepAction.hh>

StepAction::StepAction(EventAction *_event): event(_event) {
   StepActionMessenger = new DetGeometryMessenger(this);
}



void StepAction::UserSteppingAction(const G4Step *aStep) {
    aStep->GetTrack()->GetVolume()->GetName();

}
void StepAction::setName(G4String name) {
    StepAction::pName=name;
    std::cout<< pName << std::endl;
}





