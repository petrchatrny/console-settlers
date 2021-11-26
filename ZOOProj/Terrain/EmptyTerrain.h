
#ifndef ZOOPROJ_EMPTYTERRAIN_H
#define ZOOPROJ_EMPTYTERRAIN_H


#include "Terrain.h"

class EmptyTerrain : public Terrain {
public:
    EmptyTerrain();
    buildings::Resources beMined(buildings::ExtractionBuilding* miner) override;
    bool canCreateBuilding() override;
    void setBuilding(buildings::Building* building) override;
    std::string getAppearance() override;
};


#endif //ZOOPROJ_EMPTYTERRAIN_H
