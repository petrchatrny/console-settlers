
#include <iostream>
#include "World.h"
#include "buildings/TownHall.h"

World::World(std::string name, int size) {
    this->m_map = new Map(size);
    this->m_name = name;
    int radniceX, radniceY;
    bool success = false;
    std::cout << "Zadej souradnice X a Y pro umisteni radnice: ";
    while(success != true) {
        std::cin >> radniceX;
        std::cin >> radniceY;
        success = this->m_map->createBuilding({radniceX, radniceY}, buildings::TownHall({radniceX, radniceY}, "Radnice")); //!!?
        if(success == false) std::cout << "[!] Chybne souradnice, zadej souradnice znovu: ";
    }
    this->townHallCoords = {radniceX, radniceY};
    this->m_map->printMap();
}

std::string World::getName() {
    return this->m_name;
}

Map *World::getMap() {
    return this->m_map;
}
