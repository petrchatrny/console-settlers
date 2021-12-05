
#ifndef ZOOPROJ_MAP_H
#define ZOOPROJ_MAP_H


#include <vector>
#include "Terrain/Terrain.h"

class Map {
private:
    int m_size;
    std::string m_mapHeader;
    std::vector<std::vector<Terrain *>> m_cells;
    void generateMap();

public:
    Map(int size);
    ~Map();
    int getSize();
    void printMap();
    bool createBuilding(buildings::Coords coords, buildings::Building* building);
    void destroyBuilding(buildings::Coords coords);
    buildings::Building* getBuilding(buildings::Coords coords);
    buildings::Resources mineTerrain(buildings::Coords coords, buildings::ExtractionBuilding* miner);
};


#endif //ZOOPROJ_MAP_H
