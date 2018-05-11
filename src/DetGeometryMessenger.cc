//
// Created by student on 05.05.18.
//

#include <G4UIcommand.hh>
#include <G4UImessenger.hh>
#include <DetGeometryMessenger.hh>

void DetGeometryMessenger::SetNewValue(G4UIcommand *command, G4String newValue) {
    if(command == cmd)
        exit(80);
    if(command == int_cmd)
        my_geom->setBoxYsize(int_cmd->GetNewIntValue(newValue));
    if(command == psi_cmd)
        my_geom->setPsi(psi_cmd->GetNewDoubleValue(newValue));
    if(command == energy_cmd) {
        my_energy->setEnergy(energy_cmd->GetNewDoubleValue(newValue));
    }
}

DetGeometryMessenger::DetGeometryMessenger(DetGeometry* geom): my_geom(geom){
    auto dir = new G4UIdirectory("/my_geom/");

    int_cmd = new G4UIcmdWithAnInteger("/my_geom/cmd1",this);

    cmd = new G4UIcommand("/my_geom/cmd2",this);

    psi_cmd = new G4UIcmdWithADouble("/my_geom/set_psi",this);
    psi_cmd->SetGuidance("Set Psi");

}

DetGeometryMessenger::DetGeometryMessenger(PrimaryGen *energy): my_energy(energy) {
    energy_cmd = new G4UIcmdWithADouble("/my_geom/energy_cmd", this);
}

DetGeometryMessenger::~DetGeometryMessenger() {

}


