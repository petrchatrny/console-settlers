
#ifndef ZOOPROJ_FOREST_H
#define ZOOPROJ_FOREST_H


#include "Terrain.h"

class Forest : public Terrain {
public:
    Forest();
    buildings::Resources beMined(buildings::ExtractionBuilding* miner) override;
    bool canCreateBuilding() override;
    void setBuilding(buildings::Building* building) override;
};


#endif //ZOOPROJ_FOREST_H
