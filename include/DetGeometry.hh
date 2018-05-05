
#ifndef CPROJECT_DETGEOMETRY_HH
#define CPROJECT_DETGEOMETRY_HH

#include "G4SystemOfUnits.hh"

#include <G4PhysicalConstants.hh>
#include "G4SolidStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4PhysicalVolumeStore.hh"

#include "G4NistManager.hh"

#include "G4PVPlacement.hh"

#include "G4Box.hh"

#include "G4VUserDetectorConstruction.hh"
#include <DetGeometryMessenger.hh>
class G4VPhysicalVolume;
class G4LogicalVolume;
class DetGeometryMessenger;


class DetGeometry  : public G4VUserDetectorConstruction
{
private:
    G4NistManager*              nist;
    G4Material*                 world_mat;
    G4double                    world_sizeXYZ;
    G4Box*                      solidWorld;
    G4LogicalVolume*            logicWorld;
    virtual G4VPhysicalVolume*  Construct();
    G4VPhysicalVolume*          physWorld;
public:
    void setBoxYsize(G4double boxYsize);

private:
    G4double                    boxYsize;
    G4double                    psi;
public:
    void setPsi(G4double psi);

private:
    DetGeometryMessenger*       detGeometryMessenger;
public:
    DetGeometry();
    virtual ~DetGeometry();
};

#endif //CPROJECT_DETGEOMETRY_HH
