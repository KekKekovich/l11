
#include "../include/DetGeometry.hh"
#include <G4VisAttributes.hh>
#include <G4GeometryManager.hh>
#include <G4RunManager.hh>
#include <G4Tubs.hh>
#include <G4Orb.hh>

DetGeometry::DetGeometry() {
    detGeometryMessenger = new DetGeometryMessenger(this);
    world_sizeXYZ = 5000 * cm;
    nist = G4NistManager::Instance();
    world_mat = nist->FindOrBuildMaterial("G4_AIR");
    tube_mat = nist->FindOrBuildMaterial("G4_GRAPHITE");
    box_mat = nist->FindOrBuildMaterial("G4_BGO");
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

    std::ofstream file2("../result2.txt");

//    G4Element *Na = new G4Element("Na", "Na", 11, 22.990*g/mole);
//    G4Element *I = new G4Element("I", "I", 53, 126.904*g/mole);
//
//    G4Material *NaI = new G4Material("NaI", 3.667*g/cm3, 2, kStateSolid);
//    NaI->AddElement(Na, 1);
//    NaI->AddElement(I, 1);
//
//    G4Element* Al = nist->FindOrBuildElement(13);
//    G4Element* Mg = nist->FindOrBuildElement(12);
//    G4Element* Fe = nist->FindOrBuildElement(26);
//    G4Element* Si = nist->FindOrBuildElement(14);
//
//    G4Material* AMG = new G4Material("AMG", 2.64*g/cm3, 4, kStateSolid);
//    AMG->AddElement(Al, 0.92);
//    AMG->AddElement(Mg, 0.06);
//    AMG->AddElement(Fe, 0.01);
//    AMG->AddElement(Si, 0.01);



    auto tubs = new G4Tubs("tube", 0, 0.05*m, 0.05*m,0, 360*deg);
    auto tubs_log = new G4LogicalVolume(tubs, tube_mat, "tubs_LOG");
    tubs_log->SetVisAttributes(G4Colour::Red());
    new  G4PVPlacement(R, position, tubs_log, "tubs_PV", logicWorld, false, 0);


    auto box = new G4Box("box", 0.05*m, 0.05*m, 0.05*m);
    auto box_log = new G4LogicalVolume(box, box_mat, "box_log");
    box_log->SetVisAttributes(G4Colour::Magenta());
    new G4PVPlacement(0, G4ThreeVector(-10*cm, 0, 0.1*m), box_log, "box", logicWorld, false, 0);

//    auto orb = new G4Orb("orb", 3*m);
//    auto orb_log = new G4LogicalVolume(orb, box_mat, "orb_log");
//    orb_log ->SetVisAttributes(G4Colour::Blue());
//    new G4PVPlacement(0, G4ThreeVector(), orb_log, "orb_pv", logicWorld, false, 0);


    file2 <<"BGO density is:   "<< box_mat-> GetDensity()/(g/cm3) << "\n";
    file2 << box_mat -> GetName() << "\n";




    return physWorld;
}

void DetGeometry::setBoxYsize(G4double boxYsize) {
    DetGeometry::boxYsize = boxYsize;

    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();

}

void DetGeometry::setPsi(G4double psi) {
    DetGeometry::psi = psi;
//    DetGeometry::phi = phi;
//    DetGeometry::theta = theta;

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

