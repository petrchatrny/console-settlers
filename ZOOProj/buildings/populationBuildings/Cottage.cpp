//
// Created by Petr on 16.11.2021.
//

#include "../../Game.h"
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
    std::cout << "Cottage{ x: " << getCoords().x << ", y: " << getCoords().y << ", name: " << getName() <<
    ", durability: " << getDurability() << ", population: " << getPopulation() << " }" << std::endl;
}

void buildings::Cottage::printHelp() {
    std::cout << "----- HELP OF COTTAGE -----" << std::endl;
    std::cout << "[0] - help" << std::endl;
    std::cout << "[1] - info about Cottage" << std::endl;
    std::cout << "[90] - will exit from the Cottage" << std::endl;
    std::cout << "---------------------------" << std::endl;
}