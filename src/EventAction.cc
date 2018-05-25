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




EventAction::EventAction(RunAction* runAction) : runAction(runAction) {
    messenger = new DetGeometryMessenger(this);
    threshold = 0;
    runAction = run;
    result = new std::map<G4String, G4double>;

}

void EventAction::setThreshold(G4double x) {
    EventAction::threshold = x;
    G4cout << threshold << "\n";


}

EventAction::~EventAction() {

}

void EventAction::BeginOfEventAction(const G4Event *event) {

}

void EventAction::EndOfEventAction(const G4Event *event) {
    std::ofstream file("../result.txt", std::ios_base::app);
    file.clear();

    for(auto it: *result) {
        file << it.first << " | " << it.second << "\n";
    }
    file.close();

    for (auto it: *result) {
        if (it.second > 0) {
            runAction->AddEvent(it.first, it.second);
        } else {
            result->clear();
        }
    }

    if (result->size() >= 0) {

        result->clear();
    }
}

void EventAction::Data(G4String name, G4double Energy) {
    if( result->find(name) == result->end()) {
        result->emplace(name, Energy);
    }
    result->find(name)->second += Energy;
}







//void EventAction::EndOfEventAction(const G4Event *anEvent) {
//
//}
