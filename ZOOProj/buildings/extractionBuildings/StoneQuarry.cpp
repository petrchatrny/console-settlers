//
// Created by Petr on 16.11.2021.
//

#include "StoneQuarry.h"

buildings::StoneQuarry::StoneQuarry(Coords coords, std::string name)
        : ExtractionBuilding(coords, name, "\U00002692", STONE) {
    m_minedStone = 0;
}

void buildings::StoneQuarry::executeCommand(int command) {
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

void buildings::StoneQuarry::mineResources() {
    // TODO Petr
}

buildings::Resources buildings::StoneQuarry::collectMinedResources() {
    int temp = m_minedStone;
    m_minedStone = 0;
    return Resources{0, temp, 0};
}

void buildings::StoneQuarry::printInfo() {
    // TODO Daniil
}

void buildings::StoneQuarry::printHelp() {
    std::cout << "----- HELP OF STONE_QUARRY -----" << std::endl;
    std::cout << "[0] - help" << std::endl;
    std::cout << "[1] - info about StoneQuarry" << std::endl;
    std::cout << "[2] - will mine resources" << std::endl;
    std::cout << "--------------------------------" << std::endl;
}
