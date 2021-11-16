//
// Created by Petr on 16.11.2021.
//

#include "BowCraft.h"

buildings::BowCraft::BowCraft(int coordX, int coordY, std::string name)
        : WeaponBuilding(coordX, coordY, name, "\U0001F3F9", 0) {
    // empty constructor
}

int buildings::BowCraft::getRequiredWood() {
    return 500;
}

int buildings::BowCraft::getRequiredStone() {
    return 150;
}

int buildings::BowCraft::getRequiredIron() {
    return 500;
}

void buildings::BowCraft::executeCommand(int command) {
    // TODO Petr
}

void buildings::BowCraft::printInfo() {
    // TODO Daniil
}

void buildings::BowCraft::printHelp() {
    // TODO Daniil
}
