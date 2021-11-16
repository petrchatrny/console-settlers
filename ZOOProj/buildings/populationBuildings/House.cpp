//
// Created by Petr on 16.11.2021.
//

#include "House.h"


buildings::House::House(int coordX, int coordY, std::string name)
        : PopulationBuilding(coordX, coordY, name, "\U0001F3E2", rand() % 12 + 7) {
    // empty constructor
}

int buildings::House::getRequiredWood() {
    return 100;
}

int buildings::House::getRequiredStone() {
    return 200;
}

int buildings::House::getRequiredIron() {
    return 0;
}

void buildings::House::executeCommand(int command) {
    // TODO Petr
}

void buildings::House::printInfo() {
    // TODO Daniil
}

void buildings::House::printHelp() {
    // TODO Daniil
}
