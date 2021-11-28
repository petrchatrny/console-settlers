//
// Created by Petr on 16.11.2021.
//

#include "Theatre.h"

buildings::Theatre::Theatre(Coords coords, std::string name)
        : MoraleBuilding(coords, name, "\U0001F3AD", 150) {

}

void buildings::Theatre::executeCommand(int command) {
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

void buildings::Theatre::printInfo() {
    // TODO Daniil
}

void buildings::Theatre::printHelp() {
    std::cout << "----- HELP OF THEATRE -----" << std::endl;
    std::cout << "[0] - help" << std::endl;
    std::cout << "[1] - info about Theatre" << std::endl;
    std::cout << "---------------------------" << std::endl;
}
