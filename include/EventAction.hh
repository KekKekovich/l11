//
// Created by student on 14.04.18.
//

#ifndef L11_EVENTACTION_HH
#define L11_EVENTACTION_HH

#include <G4UserEventAction.hh>
#include <RunAction.hh>
#include <pwdefs.hh>
#include <DetGeometryMessenger.hh>

class RunAction;
class DetGeometryMessenger;


class EventAction : public G4UserEventAction{

//private:
//    G4double EnergyDeposit;
    RunAction* run;
    std::map<G4String, G4double> *result;
//public:
//    void addEnergyDeposit(G4double EnergyDeposit);
//
//    EventAction(RunAction* run);
//
public:


    virtual void BeginOfEventAction(const G4Event *anEvent);

    virtual void EndOfEventAction(const G4Event *anEvent);
RunAction* runAction;
    G4double threshold;
    DetGeometryMessenger *messenger;

public:
    EventAction();

    void Data(G4String name, G4double Energy);

    void setThreshold(G4double Threshold);

    EventAction(RunAction *runAction);

    virtual ~EventAction();

};
#endif //L11_EVENTACTION_HH
