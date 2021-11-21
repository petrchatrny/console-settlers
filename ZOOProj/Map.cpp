
#include <iostream>
#include "Map.h"
#include "Terrain/EmptyTerrain.h"
#include "Terrain/SecretCave.h"

Map::Map(int size) {
    this->m_size = size;
    this->generateMap();
    this->printMap();
}

int Map::getSize() {
    return this->m_size;
}

std::vector<std::vector<Entity *>> Map::getCells() {
    return this->m_cells;
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

bool Map::placeEntity(Entity *entity, int coordX, int coordY) {
    this->m_cells.at(coordX-1).at(coordY-1) = entity;
}
