
#include <iostream>
#include "World.h"
#include "buildings/TownHall.h"

World::World(std::string name, int size) {
    this->m_map = new Map(size);
    this->m_name = name;
    buildings::TownHall* townHall = nullptr;
    buildings::Coords thCoords = buildings::Coords{};
    bool success = false;
    this->m_map->printMap();
    std::cout << "Zadej souradnice X a Y pro umisteni radnice: ";
    while(success != true) {
        std::cin >> thCoords.x;
        std::cin >> thCoords.y;
        townHall = new buildings::TownHall(thCoords, "Radnice");
        success = this->m_map->createBuilding(thCoords, townHall);
        if(success == false) std::cout << "[!] Chybne souradnice, zadej souradnice znovu: ";
    }
    this->m_townHall = townHall;
    this->m_map->printMap();
}

std::string World::getName() {
    return this->m_name;
}

Map *World::getMap() {
    return this->m_map;
}

buildings::TownHall *World::getTownHall() {
    return this->m_townHall;
}

void World::tryToInvokeAttack() {

}