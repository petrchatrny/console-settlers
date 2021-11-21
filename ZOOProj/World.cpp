
#include <iostream>
#include "World.h"
#include "Terrain/EmptyTerrain.h"

World::World(std::string name, int size) {
    this->m_map = new Map(size);
    this->m_name = name;
    int radniceX, radniceY;
    std::cout << "Zadej souradnice X a Y pro umisteni radnice: ";
    std::cin >> radniceX;
    std::cin >> radniceY;
    //this->m_map->placeEntity(new buildings::TownHall(radniceX, radniceY, "X"), radniceX, radniceY); ??? TownHall weird attr, Buildings protected
    this->m_map->placeEntity(new EmptyTerrain(radniceX, radniceY), radniceX, radniceY);
    this->m_map->printMap();
}

std::string World::getName() {
    return this->m_name;
}

Map *World::getMap() {
    return this->m_map;
}
