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

class DetGeometry;
class PrimaryGen;
class DetGeometryMessenger: public G4UImessenger{

    G4UIcmdWithAnInteger * int_cmd;
    G4UIcmdWithADouble * psi_cmd;
    G4UIcommand * cmd;
    G4UIcmdWithADouble * energy_cmd;

    DetGeometry* my_geom;
    PrimaryGen * my_energy;
public:
    DetGeometryMessenger(DetGeometry* geom);
    DetGeometryMessenger(PrimaryGen* energy);
    ~DetGeometryMessenger();
    void SetNewValue(G4UIcommand *command, G4String newValue) override;
};

#endif //L11_DETGEOMETRYMESSENGER_HH