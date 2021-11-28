//
// Created by Petr on 16.11.2021.
//

#include "IronMine.h"

buildings::IronMine::IronMine(Coords coords, std::string name)
        : ExtractionBuilding(coords, name, "\U000026CF", IRON) {
    m_minedIron = 0;
}

void buildings::IronMine::executeCommand(int command) {
    switch (command) {
        case 0:
            printHelp();
            break;
        case 1:
            printInfo();
            break;
        case 2:
            mineResources();
            break;
        default:
            break;
    }
}

void buildings::IronMine::mineResources() {
    // TODO Petr
}

buildings::Resources buildings::IronMine::collectMinedResources() {
    int temp = m_minedIron;
    m_minedIron = 0;
    return Resources{0, 0, temp};
}

void buildings::IronMine::printInfo() {
    // TODO Daniil
}

void buildings::IronMine::printHelp() {
    std::cout << "----- HELP OF IRON_MINE -----" << std::endl;
    std::cout << "[0] - help" << std::endl;
    std::cout << "[1] - info about IronMine" << std::endl;
    std::cout << "[2] - will mine resources" << std::endl;
    std::cout << "-----------------------------" << std::endl;
}
