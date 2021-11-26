
#include <iostream>
#include "Map.h"
#include "Terrain/EmptyTerrain.h"
#include "Terrain/SecretCave.h"

Map::Map(int size) {
    this->m_size = size;
    this->m_cells = {};
    this->generateMap();
}

Map::~Map() {
    for(std::vector<Terrain*> terrainRow: m_cells) {
        for(Terrain* terrain: terrainRow) {
            delete terrain;
        }
    }
}

int Map::getSize() {
    return this->m_size;
}

void Map::generateMap() {
    this->m_cells.resize(this->m_size);
    for(int i = 0; i < this->m_size; i++) {
        for(int j = 0; j < this->m_size; j++) {
            this->m_cells.at(i).push_back(new SecretCave(i, j));
        }
    }
}

void Map::printMap() {
    std::cout << "---------------" << std::endl;
    for(int i = 0; i < this->m_cells.size(); i++) {
        std::cout << "| ";
        for(int j = 0; j < this->m_cells.size(); j++) {
            std::cout << this->m_cells.at(i).at(j)->getAppearance() << " ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "---------------" << std::endl;
}

bool Map::createBuilding(buildings::Coords coords, buildings::Building *building) {
    if(this->m_cells.at(coords.x).at(coords.y)->canCreateBuilding()) {
        this->m_cells.at(coords.x).at(coords.y)->setBuilding(building);
        return true;
    }
    return false;
}

buildings::Building *Map::getBuilding(buildings::Coords coords) {
    return this->m_cells.at(coords.x).at(coords.y)->getBuilding();
}

buildings::Resources Map::mineTerrain(buildings::Coords coords, buildings::ExtractionBuilding *miner) {
    return this->m_cells.at(coords.x).at(coords.y)->beMined(miner);
}
