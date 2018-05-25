//
// Created by student on 14.04.18.
//

#include <EventAction.hh>
#include <G4Step.hh>
#include <G4UserSteppingAction.hh>
#include <StepAction.hh>

StepAction::StepAction(EventAction* event) {
   StepActionMessenger = new DetGeometryMessenger(this);
    eventAction = event;
    particleName = "pName";


}



void StepAction::UserSteppingAction(const G4Step *aStep) {
    if (aStep->GetTotalEnergyDeposit() > 0
        && aStep->GetTrack()->GetVolume()->GetLogicalVolume()->GetMaterial()->GetName() == "G4_BGO"
        && (aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "gamma" ||
            aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "e-")) {
        eventAction->Data(aStep->GetTrack()->GetVolume()->GetName(), aStep->GetTotalEnergyDeposit());
    }

}
void StepAction::setName(G4String name) {
    StepAction::pName=name;
    std::cout<< pName << "Part.Name" <<std::endl;
}





