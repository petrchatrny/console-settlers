//
// Created by Petr on 16.11.2021.
//

#include "SwordCraft.h"

buildings::SwordCraft::SwordCraft(int coordX, int coordY, std::string name)
        : WeaponBuilding(coordX, coordY, name, "\U00002694", 250) {
    // empty constructor
}

int buildings::SwordCraft::getRequiredWood() {
    return 300;
}

int buildings::SwordCraft::getRequiredStone() {
    return 200;
}

int buildings::SwordCraft::getRequiredIron() {
    return 300;
}

void buildings::SwordCraft::executeCommand(int command) {
    // TODO Petr
}

void buildings::SwordCraft::printInfo() {
    // TODO Daniil
}

void buildings::SwordCraft::printHelp() {
    // TODO Daniil
}