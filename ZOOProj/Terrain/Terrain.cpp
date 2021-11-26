#include "Terrain.h"

Terrain::Terrain(std::string appearance) {
    this->m_appearance = appearance;
    this->m_building = nullptr;
}

std::string Terrain::getAppearance() {
    return this->m_appearance;
}

buildings::Building *Terrain::getBuilding() {
    return this->m_building;
}