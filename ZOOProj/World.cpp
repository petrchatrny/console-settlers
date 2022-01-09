
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
    return (m_attackCounter * 300 + 100)-(m_townHall->getTotalDefence());
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
            Game::getInstance()->printMessage("Attack of natives begun!", INFO);
            float damage = calculateAttackDamage();
            invokeAttack(damage);
            Game::getInstance()->printMessage("End of attack. Natives dealt " + std::to_string(damage) + " damage to your buildings." , INFO);
        } else {
            Game::getInstance()->printMessage("Natives tried to attack you but failed", INFO);
        }
    }
}

void World::invokeAttack(float damage) {
    m_attackCounter++;
    std::vector<buildings::Building *> buildings = m_townHall->getMergedBuildings();

    // remove buildings
    int i = 0;
    while (damage > 0 && i < buildings.size()) {
        if (buildings.at(i)->getDurability() <= damage) {
            // shrink damage
            damage -= buildings.at(i)->getDurability();

            // remove destroyed building from map
            m_map->destroyBuilding(buildings.at(i)->getCoords());

            // remove destroyed building from townHall
            m_townHall->destroyBuilding(buildings.at(i));

            // remove building from main memory
            delete buildings.at(i);
        } else {
            buildings.at(i)->takeDamage(damage);
        }
        i++;
    }

    // check damage depletion after removing buildings
    if (damage > 0) {
        // try to destroy TownHall and end the game
        if (m_townHall->getDurability() <= damage) {
            Game::getInstance()->end(GameResult::LOSE);
        } else {
            m_townHall->takeDamage(damage);

            // check win
            if (m_attackCounter == 2) {
                Game::getInstance()->end(GameResult::WIN);
            }
        }
    }
}

World::~World() {
    delete m_map;
    delete m_townHall;
}