//
// Created by student on 14.04.18.
//

#include <G4Run.hh>
#include <G4UserRunAction.hh>
#include <RunAction.hh>
#include <G4SIunits.hh>
#include <fstream>

void RunAction::BeginOfRunAction(const G4Run *aRun) {
    res->clear();
    N1=0;
    int nStep = 100;
    G4double eMax = 10 * MeV;
    for( int i = 0; i < nStep; i++) {
        res->emplace(i * eMax / nStep / (1.602176*pow(10,-13)), 0);
    }

//    result = 0;
}

void RunAction::EndOfRunAction(const G4Run *aRun) {
    std::fstream file1("../result1.txt");
    for(auto it: *res) {
        file1 << it.first << " | " << it.second << "\n";
    }
    file1 << "\nbox - " << N1  <<"\n";
    file1.close();
    G4cout << "11111111111111111111111   "<<N1<<"\n";

}
RunAction::RunAction() {
    res = new std::map<G4double, G4int>;
    N1 = 0;

}

RunAction::~RunAction() {
    delete res;
}

void RunAction::AddEvent(G4String name, G4double energy) {
    auto it = res->lower_bound(energy);
    it->second++;

    if (name == "box") {
        N1++;
    }
}

//void RunAction::setResult() {
//    RunAction::result ++;
//}
