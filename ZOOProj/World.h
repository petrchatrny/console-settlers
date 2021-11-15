
#ifndef ZOOPROJ_WORLD_H
#define ZOOPROJ_WORLD_H


#include <string>
#include "Map.h"

class World {
private:
    std::string m_name;
    Map* m_map;
    float calculateAttackDamage();
    void invokeAttack(float damage);

public:
    World(std::string name, int size, int coordX, int coordY);
    std::string getName();
    Map* getMap();
    void tryToInvokeAttack();
};


#endif //ZOOPROJ_WORLD_H
