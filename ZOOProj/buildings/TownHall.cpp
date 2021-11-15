//
// Created by Petr on 15.11.2021.
//

#include "TownHall.h"

buildings::TownHall::TownHall(int coordX, int coordY, std::string name)
        : Building(coordX, coordY, name, "\U0001F3DB") {
    m_woodAmount = 100;
    m_stoneAmount = 100;
    m_ironAmount = 100;
}

int buildings::TownHall::getTotalPopulation() {
    // TODO Petr
    return 0;
}

int buildings::TownHall::getTotalMorale() {
    // TODO Petr
    return 0;
}

int buildings::TownHall::getTotalDefence() {
    // TODO Petr
    return 0;
}

void buildings::TownHall::createNewBuilding(BuildingType type, int coordX, int coordY, std::string name) {
    // TODO Petr
}

void buildings::TownHall::collectResourcesFromExtractionBuilding(int coordX, int coordY) {
    // TODO Petr
}

void buildings::TownHall::executeCommand(int command) {
    // TODO Petr
}

void buildings::TownHall::printInfo() {
    // TODO Daniil
}

void buildings::TownHall::printHelp() {
    // TODO Daniil
}
