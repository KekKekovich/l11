//
// Created by student on 14.04.18.
//

#ifndef L11_EVENTACTION_HH
#define L11_EVENTACTION_HH

#include <G4UserEventAction.hh>
#include <RunAction.hh>
class EventAction : public G4UserEventAction{
private:
    G4double EnergyDeposit;
    RunAction* run;
public:
    void addEnergyDeposit(G4double EnergyDeposit);

    EventAction(RunAction* run);

public:


    void BeginOfEventAction(const G4Event *anEvent) override;

    void EndOfEventAction(const G4Event *anEvent) override;
};
#endif //L11_EVENTACTION_HH
