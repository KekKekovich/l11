
#include <G4Neutron.hh>
#include <Randomize.hh>
#include <DetGeometryMessenger.hh>

PrimaryGen::PrimaryGen()
{
    detGeometryMessenger = new DetGeometryMessenger(this);
    gun = new G4ParticleGun(1);
    G4cout<<"Primary particles generator is created successfully\t\tOK!!!"<<G4endl;
    gun->SetParticleDefinition(G4Gamma::GammaDefinition());
    gun->SetParticlePosition(G4ThreeVector(0, 0, -10*cm));
    gun->SetParticleMomentumDirection(G4ThreeVector(0,0,1));

}

PrimaryGen::~PrimaryGen()
{
    delete gun;

}

void PrimaryGen::GeneratePrimaries(G4Event* anEvent) {
    gun->SetParticleEnergy(energy);
    G4cout << " Energy = " << energy << "\n";
    gun->GeneratePrimaryVertex(anEvent);
}

void PrimaryGen::setEnergy(G4double energy) {
    PrimaryGen::energy = energy* keV;
}







