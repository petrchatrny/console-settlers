//
// Created by Petr on 16.11.2021.
//

#include "Theatre.h"

buildings::Theatre::Theatre(int coordX, int coordY, std::string name)
        : CultureBuilding(coordX, coordY, name, "", 150) {

}

int buildings::Theatre::getRequiredWoodAmount() {
    return 300;
}

int buildings::Theatre::getRequiredStoneAmount() {
    return 0;
}

int buildings::Theatre::getRequiredIronAmount() {
    return 0;
}

void buildings::Theatre::executeCommand(int command) {
    // TODO Petr
}

void buildings::Theatre::printInfo() {
    // TODO Daniil
}

void buildings::Theatre::printHelp() {
    // TODO Daniil
}
