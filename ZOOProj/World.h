
#ifndef ZOOPROJ_WORLD_H
#define ZOOPROJ_WORLD_H


#include <string>
#include "Map.h"
#include "buildings/Building.h"
#include "buildings/TownHall.h"

class World {
private:
    int m_attackCounter;
    std::string m_name;
    Map* m_map;
    buildings::TownHall* m_townHall;
    float calculateAttackDamage();
    void invokeAttack(float damage);
    bool dealDamageToGroupOfBuildings(std::vector<buildings::Building *> buildings, float &damage);

public:
    World(std::string name, int size);
    ~World();
    std::string getName();
    Map* getMap();
    void tryToInvokeAttack();
    buildings::TownHall* getTownHall();
};


#endif //ZOOPROJ_WORLD_H
