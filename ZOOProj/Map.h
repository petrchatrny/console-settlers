
#ifndef ZOOPROJ_MAP_H
#define ZOOPROJ_MAP_H


#include <vector>
#include "Entity.h"

class Map {
private:
    int m_size;
    std::vector<std::vector<Entity *>> m_cells;
    std::vector<std::vector<Entity *>> generateMap();

public:
    Map(int size);
    int getSize();
    std::vector<std::vector<Entity *>> getCells();
    void printMap();
    bool placeEntity(Entity *entity, int coordX, int coordY);
    bool deleteEntity(Entity *destroyer, int coordX, int coordY);
};


#endif //ZOOPROJ_MAP_H
