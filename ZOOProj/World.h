
#ifndef ZOOPROJ_WORLD_H
#define ZOOPROJ_WORLD_H


#include <string>
#include "Map.h"
#include "buildings/Building.h"

class World {
private:
    std::string m_name;
    Map* m_map;
    buildings::Coords townHallCoords;
    float calculateAttackDamage();
    void invokeAttack(float damage);

public:
    World(std::string name, int size);
    std::string getName();
    Map* getMap();
    void tryToInvokeAttack();
};


#endif //ZOOPROJ_WORLD_H
