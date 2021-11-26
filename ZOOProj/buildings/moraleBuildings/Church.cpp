//
// Created by Petr on 16.11.2021.
//

#include "Church.h"

buildings::Church::Church(Coords coords, std::string name)
        : MoraleBuilding(coords, name, "\U000026EA", 300) {

}

void buildings::Church::executeCommand(int command) {
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

void buildings::Church::printInfo() {
    // TODO Daniil
}

void buildings::Church::printHelp() {
    // TODO Daniil
}
