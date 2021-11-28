//
// Created by Petr on 16.11.2021.
//

#include <Game.h>
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
        case 90:
            Game::getInstance()->quitTheBuilding();
            break;
        default:
            break;
    }
}

void buildings::Theatre::printInfo() {
    // TODO Daniil
}

void buildings::Theatre::printHelp() {
    // TODO Daniil
}
