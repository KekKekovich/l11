//
// Created by student on 14.04.18.
//

#include <G4Event.hh>
#include <G4UserEventAction.hh>
#include <EventAction.hh>
#include <G4SystemOfUnits.hh>
#include <RunAction.hh>

//void EventAction::BeginOfEventAction(const G4Event *anEvent) {
//    EnergyDeposit = 0;
//}




EventAction::EventAction(RunAction* _runAction) : runAction(_runAction) {
    messenger = new DetGeometryMessenger(this);
    threshold = 0;

}

void EventAction::setThreshold(G4double x) {
    EventAction::threshold = x;
    G4cout << threshold << "\n";


}

EventAction::~EventAction() {

}

void EventAction::BeginOfEventAction(const G4Event *anEvent) {
    G4UserEventAction::BeginOfEventAction(anEvent);
}

void EventAction::EndOfEventAction(const G4Event *anEvent) {
    G4UserEventAction::EndOfEventAction(anEvent);
}



//void EventAction::EndOfEventAction(const G4Event *anEvent) {
//
//}
