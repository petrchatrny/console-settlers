
#ifndef ZOOPROJ_MOUNTAIN_H
#define ZOOPROJ_MOUNTAIN_H


#include "Terrain.h"

class Mountain : public Terrain {
public:
    Mountain();
    buildings::Resources beMined(buildings::ExtractionBuilding* miner) override;
    bool canCreateBuilding() override;
    void setBuilding(buildings::Building* building) override;
};


#endif //ZOOPROJ_MOUNTAIN_H
