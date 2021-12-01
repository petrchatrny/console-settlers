//
// Created by Petr on 16.11.2021.
//

#include "../../Game.h"
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
    std::cout << "Theatre{ x: " << getCoords().x << ", y: " << getCoords().y << ", name: " <<
    getName() << ", durability: " << getDurability() << " }" << std::endl;
}

void buildings::Theatre::printHelp() {
    std::cout << "----- HELP OF THEATRE -----" << std::endl;
    std::cout << "[0] - help" << std::endl;
    std::cout << "[1] - info about Theatre" << std::endl;
    std::cout << "[90] - will exit from the Theatre" << std::endl;
    std::cout << "---------------------------" << std::endl;
}
