//
// Created by Petr on 16.11.2021.
//

#include "LumberjackHouse.h"

buildings::LumberjackHouse::LumberjackHouse(int coordX, int coordY, std::string name)
        : ExtractionBuilding(coordX, coordY, name, "\U0001FA93") {
    m_woodAmount = 0;
}

int buildings::LumberjackHouse::getWoodAmount() {
    return m_woodAmount;
}

int buildings::LumberjackHouse::getRequiredWood() {
    return 100;
}

int buildings::LumberjackHouse::getRequiredStone() {
    return 0;
}

int buildings::LumberjackHouse::getRequiredIron() {
    return 0;
}

void buildings::LumberjackHouse::executeCommand(int command) {
    // TODO Petr
}

void buildings::LumberjackHouse::nullifyInventory() {
    m_woodAmount = 0;
}

void buildings::LumberjackHouse::printInfo() {
    // TODO Daniil
}

void buildings::LumberjackHouse::printHelp() {
    // TODO Daniil
}

void buildings::LumberjackHouse::mineResources() {
    // TODO Petr
}
