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
    if(command == cmd1) {
        G4cout<<"QQ"<<"\n";
    }
    if(command == mat_cmd) {
        my_geom -> setDetMaterial(newValue);
    }
    if(command == cmdPosition) {
        my_geom ->setPosition(cmdPosition -> GetNew3VectorValue(newValue));
    }
    if(command == threshold_cmd) {
        my_event ->setThreshold(threshold_cmd -> GetNewDoubleValue(newValue));
    }
    if(command == cmd_gunpos) {
        my_energy ->setPosition(cmd_gunpos -> GetNew3VectorValue(newValue));
    }
    if(command == name_cmd) {
        my_name ->setName(newValue);
    }
}



DetGeometryMessenger::DetGeometryMessenger(DetGeometry* geom): my_geom(geom){
    auto dir = new G4UIdirectory("/my_geom/");

    int_cmd = new G4UIcmdWithAnInteger("/my_geom/cmd1",this);
    cmd1 = new G4UIcommand("/my_geom/cmd3",this);

    cmd = new G4UIcommand("/my_geom/cmd2",this);

    psi_cmd = new G4UIcmdWithADouble("/my_geom/set_psi",this);
    psi_cmd->SetGuidance("Set Psi");
    mat_cmd = new G4UIcmdWithAString("/my_geom/cmdMat",this);
    mat_cmd -> SetParameterName("name",false);
    cmdPosition = new G4UIcmdWith3Vector("/my_geom/Position",this);

}

DetGeometryMessenger::DetGeometryMessenger(PrimaryGen *energy): my_energy(energy) {
    energy_cmd = new G4UIcmdWithADouble("/my_geom/energy_cmd", this);
    cmd_gunpos = new G4UIcmdWith3Vector("/my_geom/gunpos",this);
}



DetGeometryMessenger::DetGeometryMessenger(StepAction *pName): my_name(pName) {
    name_cmd = new G4UIcmdWithAString("/my_geom/name_cmd",this);
}

DetGeometryMessenger::DetGeometryMessenger(EventAction *event): my_event(event) {
    threshold_cmd = new G4UIcmdWithADouble("/my_geom/threshold_cmd", this);
}

DetGeometryMessenger::~DetGeometryMessenger() {

}




