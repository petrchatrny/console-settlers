
#include "Mountain.h"

Mountain::Mountain() : Terrain("M") {}

bool Mountain::canCreateBuilding() {
    return false;
}

void Mountain::setBuilding(buildings::Building *building) {}

buildings::Resources Mountain::beMined(buildings::ExtractionBuilding *miner) {
    if(miner->getResourceOutputType() == buildings::STONE) {
        return buildings::Resources{0, 150, 0};
    }
    return buildings::Resources{0, 0, 0};
}