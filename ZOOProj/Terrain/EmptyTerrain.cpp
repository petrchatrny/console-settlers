
#include "EmptyTerrain.h"

EmptyTerrain::EmptyTerrain() : Terrain(".") {}

bool EmptyTerrain::canCreateBuilding() {
    return (this->m_building == nullptr);
}

void EmptyTerrain::setBuilding(buildings::Building *building) {
    if(this->m_building == nullptr || building == nullptr) {
        this->m_building = building;
    }
}

std::string EmptyTerrain::getAppearance() {
    if(this->m_building != nullptr) {
        return this->m_building->getAppearance();
    }
    return this->m_appearance;
}

buildings::Resources EmptyTerrain::beMined(buildings::ExtractionBuilding *miner) {
    return buildings::Resources{0, 0, 0};
}