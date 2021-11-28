
#include <iostream>
#include <ctime>
#include "World.h"
#include "buildings/TownHall.h"
#include "Game.h"

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

bool World::dealDamageToGroupOfBuildings(std::vector<buildings::Building*> buildings, float &damage) {
    for (int i = 0; i < buildings.size(); i++) {
        if (buildings.at(i)->getDurability() < damage) {
            damage -= buildings.at(i)->getDurability();

            // remove it from map
            m_map->destroyBuilding(buildings.at(i)->getCoords());

            // remove it from vector
            buildings.erase(buildings.begin() + i);
        } else {
            buildings.at(i)->takeDamage(damage);
            return true;
        }
    }
    return false;
}

void World::invokeAttack(float damage) {
    this->m_attackCounter++;
    bool damageDepletion;
    std::vector<buildings::Building *> buildings;

    // destroy Weapon buildings
    buildings.insert(buildings.end(), m_townHall->getWeaponBuildings().begin(), m_townHall->getWeaponBuildings().end());
    damageDepletion = dealDamageToGroupOfBuildings(buildings, damage);
    if (damageDepletion) {
        return;
    }

    // destroy Extraction buildings
    buildings.clear();
    buildings.insert(buildings.end(), m_townHall->getExtractionBuildings().begin(),
                     m_townHall->getExtractionBuildings().end());
    damageDepletion = dealDamageToGroupOfBuildings(buildings, damage);
    if (damageDepletion) {
        return;
    }

    // destroy Morale Buildings
    buildings.clear();
    buildings.insert(buildings.end(), m_townHall->getMoraleBuildings().begin(), m_townHall->getMoraleBuildings().end());
    damageDepletion = dealDamageToGroupOfBuildings(buildings, damage);
    if (damageDepletion) {
        return;
    }

    // destroy Population Buildings
    buildings.clear();
    buildings.insert(buildings.end(), m_townHall->getPopulationBuildings().begin(),
                     m_townHall->getPopulationBuildings().end());
    damageDepletion = dealDamageToGroupOfBuildings(buildings, damage);
    if (damageDepletion) {
        return;
    }

    // try to destroy TownHall and end the game
    if (m_townHall->getDurability() <= damage) {
        Game::getInstance()->end(GameResult::LOSE);
        return;
    }
    m_townHall->takeDamage(damage);
}

World::~World() {
    delete m_map;
    delete m_townHall;
}