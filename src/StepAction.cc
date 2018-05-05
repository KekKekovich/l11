//
// Created by student on 14.04.18.
//

#include <EventAction.hh>
#include <G4Step.hh>
#include <G4UserSteppingAction.hh>
#include <StepAction.hh>

StepAction::StepAction(EventAction *_event) {
    eventAction = _event;
}



void StepAction::UserSteppingAction(const G4Step *aStep) {
    aStep->GetTrack()->GetVolume()->GetName();

}
