
#include <iostream>
#include <ctime>
#include "Map.h"
#include "Terrain/EmptyTerrain.h"
#include "Terrain/SecretCave.h"
#include "buildings/moraleBuildings/Theatre.h"
#include "buildings/moraleBuildings/Church.h"
#include "Terrain/Forest.h"
#include "Terrain/Mountain.h"

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
    srand((unsigned int)time(NULL));
    bool secretCaveAlready = false;
    this->m_cells.resize(this->m_size);
    for(int i = 0; i < this->m_size; i++) {
        for(int j = 0; j < this->m_size; j++) {
            switch(rand() % 6) {
                case 0:
                case 3:
                    this->m_cells.at(i).push_back(new EmptyTerrain());
                    break;
                case 1:
                case 2:
                case 4:
                case 5:
                    switch(rand() % 3) {
                        case 0:
                            this->m_cells.at(i).push_back(new Forest());
                            break;
                        case 1:
                            this->m_cells.at(i).push_back(new Mountain());
                            break;
                        case 2:
                            if(secretCaveAlready) {
                                switch (rand() % 2) {
                                    case 0:
                                        this->m_cells.at(i).push_back(new Forest());
                                        break;
                                    case 1:
                                        this->m_cells.at(i).push_back(new Mountain());
                                        break;
                                }
                            } else {
                                this->m_cells.at(i).push_back(new SecretCave());
                                secretCaveAlready = true;
                            }
                            break;
                    }
                    break;
            }
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
