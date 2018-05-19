
#include "../include/DetGeometry.hh"
#include <G4VisAttributes.hh>
#include <G4GeometryManager.hh>
#include <G4RunManager.hh>
#include <G4Tubs.hh>

DetGeometry::DetGeometry() {
    detGeometryMessenger = new DetGeometryMessenger(this);
    world_sizeXYZ = 50 * cm;
    nist = G4NistManager::Instance();
    world_mat = nist->FindOrBuildMaterial("G4_AIR");
    box_mat = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");
    G4cout << "Geometry of detector is build successfully\t\t\t\t\t\tOK!!!" << G4endl;
    boxYsize = 10 * cm;
    position = G4ThreeVector(-10*cm,0,0);
//    rotation = 45*deg;
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

    auto R = new G4RotationMatrix;


    R -> rotateX(0);
    R -> rotateY(psi*deg);
    R -> rotateZ(0);

    auto tubs = new G4Tubs("tube", 0, 0.5*m, 3*m,0, 360*deg);
    auto tubs_log = new G4LogicalVolume(tubs, box_mat, "tubs_LOG");
    tubs_log->SetVisAttributes(G4Colour::Red());
    new  G4PVPlacement(R, position, tubs_log, "tubs_PV", logicWorld, false, 0);

    return physWorld;
}

void DetGeometry::setBoxYsize(G4double boxYsize) {
    DetGeometry::boxYsize = boxYsize;

    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();

}

void DetGeometry::setPsi(G4double psi) {
    DetGeometry::psi = psi;
    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();
}

void DetGeometry::setDetMaterial(G4String newValue) {
    box_mat = nist->FindOrBuildMaterial(newValue);
    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();
}

void DetGeometry::setPosition(G4ThreeVector vect) {
    DetGeometry::position = vect;
    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();
}

//void DetGeometry::setRotation(G4double rot) {
//    DetGeometry::rotation = rot;
//    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
//    G4RunManager::GetRunManager()->ReinitializeGeometry();
//}

