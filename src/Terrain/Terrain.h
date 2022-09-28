#ifndef ZOOPROJ_TERRAIN_H
#define ZOOPROJ_TERRAIN_H


#include <string>
#include "../buildings/Building.h"
#include "../buildings/extractionBuildings/ExtractionBuilding.h"

class Terrain {

protected:
    Terrain(std::string appearance);
    std::string m_appearance;
    buildings::Building* m_building;

public:
    virtual ~Terrain() = default;
    virtual std::string getAppearance();
    buildings::Building* getBuilding();
    virtual buildings::Resources beMined(buildings::ExtractionBuilding* miner) = 0;
    virtual bool canCreateBuilding() = 0;
    virtual void setBuilding(buildings::Building* building) = 0;
};


#endif //ZOOPROJ_TERRAIN_H
