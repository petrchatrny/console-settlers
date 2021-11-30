
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

    Game::getInstance()->printMessage("Enter coordinates for town hall (x y): ", INPUT);
    while (!success) {
        std::cin >> thCoords.x;
        std::cin >> thCoords.y;
        townHall = new buildings::TownHall(thCoords, "TownHall");
        success = this->m_map->createBuilding(thCoords, townHall);
        if (!success) {
            Game::getInstance()->printMessage("Wrong coordinates entered", ERROR);
            Game::getInstance()->printMessage("Enter town hall's coordinates again (x y): ", INPUT);
        }
    }

    this->m_townHall = townHall;
    this->m_map->printMap();
    Game::getInstance()->printMessage("Town hall successfully built, game begins!", INFO);
}

std::string World::getName() {
    return this->m_name;
}

Map *World::getMap() {
    return this->m_map;
}

float World::calculateAttackDamage() {
    return (2*this->m_attackCounter*1000)-(m_townHall->getTotalDefence());
}

void World::tryToInvokeAttack() {
    srand((unsigned int)time(NULL));
    if(this->m_attackCounter < 3) {
        bool attack = false;
        int tempAttackCounter = this->m_attackCounter+1;
        double defenseOdds = (((m_townHall->getTotalPopulation()+1)*20)+((m_townHall->getTotalMorale()+1)*0.86))-(600-((rand() % tempAttackCounter + 1)*162));
        if(defenseOdds > 500) {
            if(rand() % 3 == 2) attack = true;
        } else {
            if(rand() % 2 == 0) attack = true;
        }
        if(attack) {
            this->invokeAttack(this->calculateAttackDamage());
        }
    }
}

bool World::dealDamageToGroupOfBuildings(std::vector<buildings::Building*> group, float &damage) {
    for (int i = 0; i < group.size(); i++) {
        if (group.at(i)->getDurability() < damage) {
            damage -= group.at(i)->getDurability();

            // remove it from map
            m_map->destroyBuilding(group.at(i)->getCoords());

            // remove it from vector
            group.erase(group.begin() + i);
        } else {
            group.at(i)->takeDamage(damage);
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