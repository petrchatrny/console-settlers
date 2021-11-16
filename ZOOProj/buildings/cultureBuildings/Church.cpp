//
// Created by Petr on 16.11.2021.
//

#include "Church.h"

buildings::Church::Church(int coordX, int coordY, std::string name)
        : CultureBuilding(coordX, coordY, name, "\U000026EA", 300) {

}

int buildings::Church::getRequiredWoodAmount() {
    return 200;
}

int buildings::Church::getRequiredStoneAmount() {
    return 350;
}

int buildings::Church::getRequiredIronAmount() {
    return 0;
}

void buildings::Church::executeCommand(int command) {
    // TODO Petr
}

void buildings::Church::printInfo() {
    // TODO Daniil
}

void buildings::Church::printHelp() {
    // TODO Daniil
}
