
#include "Forest.h"

Forest::Forest() : Terrain("\U0001F332") {}

bool Forest::canCreateBuilding() {
    return false;
}

void Forest::setBuilding(buildings::Building *building) {}

buildings::Resources Forest::beMined(buildings::ExtractionBuilding *miner) {
    if(miner->getResourceOutputType() == buildings::WOOD) {
        return buildings::Resources{150, 0, 0};
    }
    return buildings::Resources{0, 0, 0};
}