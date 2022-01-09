
#include <iostream>
#include <ctime>
#include <map>
#include "Map.h"
#include "Terrain/EmptyTerrain.h"
#include "Terrain/SecretCave.h"
#include "Terrain/Forest.h"
#include "Terrain/Mountain.h"

Map::Map(int size) {
    this->m_size = size;
    this->m_cells = {};
    this->generateMap();
    std::map<int, std::string> headerMap = {
            {6, "============================="},
            {8, "====================================="},
            {12, "====================================================="}
    };
    this->m_mapHeader = headerMap[this->m_size];
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
    std::cout << this->m_mapHeader << std::endl;
    for(int i = 0; i < this->m_cells.size(); i++) {
        std::cout << "|\t";
        for(int j = 0; j < this->m_cells.size(); j++) {
            std::cout << this->m_cells.at(i).at(j)->getAppearance() << "\t";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << this->m_mapHeader << std::endl;
}

bool Map::createBuilding(buildings::Coords coords, buildings::Building *building) {
    if(coords.x >= 0 && coords.y >= 0 && coords.x < this->m_size && coords.y < this->m_size) {
        if(this->m_cells.at(coords.x).at(coords.y)->canCreateBuilding()) {
            this->m_cells.at(coords.x).at(coords.y)->setBuilding(building);
            return true;
        }
    }
    return false;
}

void Map::destroyBuilding(buildings::Coords coords) {
    m_cells.at(coords.x).at(coords.y)->setBuilding(nullptr);
}

buildings::Building *Map::getBuilding(buildings::Coords coords) {
    if (coords.x < 0 || coords.y < 0 || coords.x > m_size - 1 || coords.y > m_size - 1) {
        return nullptr;
    }
    return this->m_cells.at(coords.x).at(coords.y)->getBuilding();
}

buildings::Resources Map::mineTerrain(buildings::Coords coords, buildings::ExtractionBuilding *miner) {
    buildings::Resources res = this->m_cells.at(coords.x).at(coords.y)->beMined(miner);
    if (res.wood != 0 || res.stone != 0 || res.iron != 0) {
        delete m_cells.at(coords.x).at(coords.y);
        m_cells.at(coords.x).at(coords.y) = new EmptyTerrain();
    }
    return res;
}
