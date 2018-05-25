//
// Created by student on 14.04.18.
//

#ifndef L11_RUNACTION_HH
#define L11_RUNACTION_HH

#include <G4UserRunAction.hh>
#include <map>
#include <G4String.hh>
//#include "Scoring.hh"

class RunAction : public G4UserRunAction{
private :
    std::map<G4double, G4int> *res;
    G4double result, N1;
//    Scoring* scoring;
public:
    void setResult();
    void AddEvent(G4String name, G4double energy);

public:
    RunAction();
    ~RunAction();
//    RunAction(Scoring* newScoring){scoring = newScoring;}
    void BeginOfRunAction(const G4Run* aRun);
    void EndOfRunAction(const G4Run* aRun);

};


#endif //L11_RUNACTION_HH
