
#ifndef ZOOPROJ_SECRETCAVE_H
#define ZOOPROJ_SECRETCAVE_H


#include "Terrain.h"

class SecretCave : public Terrain {
public:
    SecretCave();
    buildings::Resources beMined(buildings::ExtractionBuilding* miner) override;
    bool canCreateBuilding() override;
    void setBuilding(buildings::Building* building) override;
};


#endif //ZOOPROJ_SECRETCAVE_H
