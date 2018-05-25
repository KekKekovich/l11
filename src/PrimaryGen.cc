
#include <G4Neutron.hh>
#include <Randomize.hh>
#include <DetGeometryMessenger.hh>
#include <G4Electron.hh>




PrimaryGen::PrimaryGen()
{
    detGeometryMessenger = new DetGeometryMessenger(this);
    gun = new G4ParticleGun(1);
    gun->SetParticleDefinition(G4Neutron::NeutronDefinition());

    gun1 = new G4ParticleGun(1);
    gun1 -> SetParticleDefinition(G4Electron::ElectronDefinition());
}

PrimaryGen::~PrimaryGen()
{
    delete gun;
    delete gun1;

}

void PrimaryGen::GeneratePrimaries(G4Event* anEvent) {

//    double R = 10*cm, px, py, pz;
//    do {
//        px = (2*G4UniformRand()-1) * cm;
//        py = (2*G4UniformRand()-1) * cm;
//        pz = (2*G4UniformRand()-1) * cm;
//    } while (sqrt(px*px + py*py + pz*pz) > R);
//    gun->SetParticlePosition(G4ThreeVector(px, py, pz));

    double x = 2*G4UniformRand()-1;
    double y = 2*G4UniformRand()-1;
    double z = 2*G4UniformRand()-1;
    double r = sqrt(x*x + y*y + z*z);
//    gun->SetParticleMomentumDirection(G4ThreeVector(x/r, y/r, z/r));

    gun->SetParticlePosition(position);
    gun->SetParticleEnergy(14*MeV);
//    G4cout << " Energy = " << energy << "\n";
    gun->SetParticleMomentumDirection(G4ThreeVector(-1,0,0));

    gun->GeneratePrimaryVertex(anEvent);


//    gun1->SetParticleEnergy(2*MeV);
//    gun1->SetParticlePosition(G4ThreeVector(100,100,100));
//    gun1->SetParticleMomentumDirection(G4ThreeVector(0,1,0));
//
//    gun1->GeneratePrimaryVertex(anEvent);

}

//void PrimaryGen::GeneratePrimaries(G4Event* anEvent) {
//    RandomSpectre a(0);
//
//    G4double E = a.RandomVariate(0,0.545, 0.01,1)[0]*MeV;
//    gun->SetParticleDefinition(G4Gamma::GammaDefinition());
//    gun->SetParticleEnergy(E);
//
//
//}

void PrimaryGen::setEnergy(G4double energy) {
    PrimaryGen::energy = energy* keV;
}

void PrimaryGen::setPosition(G4ThreeVector vect) {
    PrimaryGen::position = vect;
}








