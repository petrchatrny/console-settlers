
#include "SecretCave.h"

SecretCave::SecretCave() : Terrain(".") {}

bool SecretCave::canCreateBuilding() {
    return false;
}

void SecretCave::setBuilding(buildings::Building *building) {}

buildings::Resources SecretCave::beMined(buildings::ExtractionBuilding *miner) {
    if (miner->getResourceOutputType() == buildings::IRON) {
        return buildings::Resources{0, 0, 1000};
    }
    return buildings::Resources{0, 0, 0};
}