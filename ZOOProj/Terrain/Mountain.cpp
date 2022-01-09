
#include "Mountain.h"

Mountain::Mountain() : Terrain("\U000026F0") {}

bool Mountain::canCreateBuilding() {
    return false;
}

void Mountain::setBuilding(buildings::Building *building) {}

buildings::Resources Mountain::beMined(buildings::ExtractionBuilding *miner) {
    if (miner->getResourceOutputType() == buildings::STONE) {
        return buildings::Resources{0, 150, 0};
    } else if (miner->getResourceOutputType() == buildings::IRON) {
        return buildings::Resources{0, 0, 150};
    }
    return buildings::Resources{0, 0, 0};
}