//
// Created by Petr on 16.11.2021.
//

#include "../../Game.h"
#include "House.h"


buildings::House::House(Coords coords, std::string name)
        : PopulationBuilding(coords, name, "\U0001F3E2", rand() % 12 + 7) {
    // empty constructor
}

void buildings::House::executeCommand(int command) {
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

void buildings::House::printInfo() {
    std::cout << "House{ x: " << getCoords().x << ", y: " << getCoords().y << ", name: " << getName() << ", durability" <<
    getDurability() << ", population: " << getPopulation() << " }" << std::endl;
}

void buildings::House::printHelp() {
    std::cout << "----- HELP OF HOUSE -----" << std::endl;
    std::cout << "[0] - help" << std::endl;
    std::cout << "[1] - info about House" << std::endl;
    std::cout << "[90] - will exit from the House" << std::endl;
    std::cout << "-------------------------" << std::endl;
}
