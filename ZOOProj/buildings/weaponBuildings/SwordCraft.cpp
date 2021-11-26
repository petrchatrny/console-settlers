//
// Created by Petr on 16.11.2021.
//

#include "SwordCraft.h"

buildings::SwordCraft::SwordCraft(Coords coords, std::string name)
        : WeaponBuilding(coords, name, "\U00002694", 250) {
    // empty constructor
}

void buildings::SwordCraft::executeCommand(int command) {
    switch (command) {
        case 0:
            printHelp();
            break;
        case 1:
            printInfo();
            break;
        default:
            break;
    }
}

void buildings::SwordCraft::printInfo() {
    // TODO Daniil
}

void buildings::SwordCraft::printHelp() {
    // TODO Daniil
}