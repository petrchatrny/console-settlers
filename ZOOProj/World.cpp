
#include <iostream>
#include <ctime>
#include "World.h"
#include "buildings/TownHall.h"

World::World(std::string name, int size) {
    this->m_map = new Map(size);
    this->m_name = name;
    this->m_attackCounter = 0;
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

float World::calculateAttackDamage() {
    return (2*this->m_attackCounter*1000)-(this->getTownHall()->getTotalDefence());
}

void World::tryToInvokeAttack() {
    srand((unsigned int)time(NULL));
    if(this->m_attackCounter < 3) {
        bool attack = false;
        double defenseOdds = ((this->getTownHall()->getTotalPopulation()*20)+(this->getTownHall()->getTotalMorale()*0.86))-(600-((rand() % this->m_attackCounter + 1)*162));
        if(defenseOdds > 500) {
            if(rand() % 3 == 2) attack = true;
        } else {
            if(rand() % 2 == 0) attack = true;
        }
        if(attack) {
            this->invokeAttack(this->calculateAttackDamage());
        } else std::cout << "[!] Probehl pokus o utok! Utok se nezdaril!" << std::endl;
        /*
         * POPULATION  |   MORALE         | TOTAL
         * 20*15 = 300 |   150*0,86 = 129 | 300+129 = 429
         * 20*25 = 500 |   450*0,86 = 387 | 500+387 = 887
         *
         * 600-((rand() % this->m_attackCounter + 1)*186) | 414 / 228 / 42
         */
    }
}

void World::invokeAttack(float damage) {
    this->m_attackCounter++;
}