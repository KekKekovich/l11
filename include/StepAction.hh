//
// Created by student on 14.04.18.
//

#ifndef L11_STEPACTION_HH
#define L11_STEPACTION_HH

#include <G4UserSteppingAction.hh>

#include <G4String.hh>
#include "EventAction.hh"
#include <DetGeometryMessenger.hh>
class DetGeometryMessenger;
class EventAction;
class StepAction: public G4UserSteppingAction{
private:
    EventAction* event;
    G4String pName;
    DetGeometryMessenger* StepActionMessenger;
public:
    StepAction(EventAction* event);
    void UserSteppingAction(const G4Step*);
    void setName(G4String name);
};


#endif //L11_STEPACTION_HH
