

#ifndef CPROJECT_ACTIONINIT_HH
#define CPROJECT_ACTIONINIT_HH

#include "G4VUserActionInitialization.hh"
#include "PrimaryGen.hh"
#include <Scoring.hh>
class ActionInit : public G4VUserActionInitialization{
private:
    Scoring* scoring;
public:
    ActionInit();
    virtual ~ActionInit();
    virtual void Build() const;
};


#endif //CPROJECT_ACTIONINIT_HH
