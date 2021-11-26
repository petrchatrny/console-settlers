//
// Created by Petr on 16.11.2021.
//

#include "BowCraft.h"

buildings::BowCraft::BowCraft(Coords coords, std::string name)
        : WeaponBuilding(coords, name, "\U0001F3F9", 450) {
    // empty constructor
}

void buildings::BowCraft::executeCommand(int command) {
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

void buildings::BowCraft::printInfo() {
    // TODO Daniil
}

void buildings::BowCraft::printHelp() {
    // TODO Daniil
}
