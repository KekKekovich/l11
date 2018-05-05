//
// Created by student on 14.04.18.
//

#include <G4Event.hh>
#include <G4UserEventAction.hh>
#include <EventAction.hh>
#include <G4SystemOfUnits.hh>
#include <RunAction.hh>

void EventAction::BeginOfEventAction(const G4Event *anEvent) {
    EnergyDeposit = 0;
}



EventAction::EventAction(RunAction* _run) : run(_run) {}


void EventAction::EndOfEventAction(const G4Event *anEvent) {

}
