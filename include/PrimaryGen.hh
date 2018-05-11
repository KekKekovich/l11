

#ifndef CPROJECT_PRIMARYGEN_HH
#define CPROJECT_PRIMARYGEN_HH


#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"

#include "G4Event.hh"

#include "G4SystemOfUnits.hh"

#include "G4Gamma.hh"
#include <DetGeometryMessenger.hh>

class G4ParticleGun;
class G4Event;
class DetGeometryMessenger;

class PrimaryGen : public G4VUserPrimaryGeneratorAction
{
private:
    G4ParticleGun*  gun;
    DetGeometryMessenger * detGeometryMessenger;
    G4double energy = 661*keV;
public:
    PrimaryGen();
    virtual ~PrimaryGen();
    virtual void GeneratePrimaries(G4Event*);
    void setEnergy(G4double energy);
};

#endif //CPROJECT_PRIMARYGEN_HH
