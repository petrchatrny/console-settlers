//
// Created by Petr on 16.11.2021.
//

#include <Game.h>
#include "Cottage.h"

buildings::Cottage::Cottage(Coords coords, std::string name)
        : PopulationBuilding(coords, name, "\U0001F3DA", rand() % 6 + 2) {
    // empty constructor
}

void buildings::Cottage::executeCommand(int command) {
    switch (command) {
        case 0:
            printHelp();
            break;
        case 1:
            printInfo();
            break;
        case 90:
            Game::getInstance()->quitTheBuilding();
            break;
        default:
            break;
    }
}

void buildings::Cottage::printInfo() {
    // TODO Daniil
}

void buildings::Cottage::printHelp() {
    // TODO Daniil
}