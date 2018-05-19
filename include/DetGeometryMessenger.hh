//
// Created by student on 05.05.18.
//

#ifndef L11_DETGEOMETRYMESSENGER_HH
#define L11_DETGEOMETRYMESSENGER_HH

#include <G4UImessenger.hh>
#include <G4UIcmdWithAnInteger.hh>
#include <DetGeometry.hh>
#include <PrimaryGen.hh>
#include <G4UIcmdWithADouble.hh>
#include <G4UIcmdWithAString.hh>
#include <G4UIcmdWith3Vector.hh>
#include <StepAction.hh>
#include <EventAction.hh>


class DetGeometry;
class PrimaryGen;
class EventAction;
class StepAction;
class DetGeometryMessenger: public G4UImessenger{

    G4UIcmdWithAnInteger * int_cmd;
    G4UIcmdWithADouble * psi_cmd;
    G4UIcommand * cmd;
    G4UIcommand * cmd1;
    G4UIcmdWithADouble * energy_cmd;
    G4UIcmdWithAString* mat_cmd;
    G4UIcmdWith3Vector * cmdPosition;
    G4UIcmdWithAString* name_cmd;
    G4UIcmdWithADouble* threshold_cmd;
    G4UIcmdWith3Vector* cmd_gunpos;
    G4UIcmdWithADouble* cmd_rotation;

    DetGeometry* my_geom;
    PrimaryGen * my_energy;
    StepAction * my_name;
    EventAction *my_event;

public:
    DetGeometryMessenger(DetGeometry* geom);
    DetGeometryMessenger(PrimaryGen* energy);
    DetGeometryMessenger(StepAction* pName);
    DetGeometryMessenger(EventAction* event);
    ~DetGeometryMessenger();
    void SetNewValue(G4UIcommand *command, G4String newValue) override;
};

#endif //L11_DETGEOMETRYMESSENGER_HH
