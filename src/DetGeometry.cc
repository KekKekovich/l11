
#include "../include/DetGeometry.hh"
#include <G4VisAttributes.hh>
#include <G4GeometryManager.hh>
#include <G4RunManager.hh>

DetGeometry::DetGeometry() {
    detGeometryMessenger = new DetGeometryMessenger(this);
    world_sizeXYZ = 50 * cm;
    nist = G4NistManager::Instance();
    world_mat = nist->FindOrBuildMaterial("G4_AIR");

    G4cout << "Geometry of detector is build successfully\t\t\t\t\t\tOK!!!" << G4endl;
    boxYsize = 10 * cm;
}

DetGeometry::~DetGeometry() {
    delete detGeometryMessenger;
}

G4VPhysicalVolume* DetGeometry::Construct() {
    G4GeometryManager::GetInstance()->OpenGeometry();
    G4PhysicalVolumeStore::GetInstance()->Clean();
    G4LogicalVolumeStore::GetInstance()->Clean();
    G4SolidStore::GetInstance()->Clean();

    solidWorld = new G4Box("solWorld", 0.5 * world_sizeXYZ, 0.5 * world_sizeXYZ, 0.5 * world_sizeXYZ);
    logicWorld = new G4LogicalVolume(solidWorld, world_mat, "logWorld");
    logicWorld->SetVisAttributes(G4VisAttributes::Invisible);
    physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "phyWorld", 0, false, 0);

    G4Box *box = new G4Box("box", 5*cm, boxYsize/2., 5*cm);
    auto box_log = new G4LogicalVolume(box, nist->FindOrBuildMaterial("G4_SODIUM_IODIDE"), "box_LOG");
    box_log->SetVisAttributes(G4Colour::Red());
    new G4PVPlacement(new G4RotationMatrix(0,0,psi), G4ThreeVector(), box_log, "box_PV", logicWorld, false, 0);

    return physWorld;
}

void DetGeometry::setBoxYsize(G4double boxYsize) {
    DetGeometry::boxYsize = boxYsize;

    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();

}

void DetGeometry::setPsi(G4double psi) {
    DetGeometry::psi = psi*deg;
    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();
}


