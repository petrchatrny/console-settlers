//
// Created by Petr on 16.11.2021.
//

#include "Cottage.h"

buildings::Cottage::Cottage(int coordX, int coordY, std::string name)
        : PopulationBuilding(coordX, coordY, name, "\U0001F3DA", rand() % 6 + 2) {
    // empty constructor
}

void buildings::Cottage::executeCommand(int command) {
    // TODO Petr
}

void buildings::Cottage::printInfo() {
    // TODO Daniil
}

void buildings::Cottage::printHelp() {
    // TODO Daniil
}