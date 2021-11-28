//
// Created by Petr on 16.11.2021.
//

#include "LumberjackHouse.h"

buildings::LumberjackHouse::LumberjackHouse(Coords coords, std::string name)
        : ExtractionBuilding(coords, name, "\U0001FA93", WOOD) {
    m_minedWood = 0;
}

void buildings::LumberjackHouse::executeCommand(int command) {
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

void buildings::LumberjackHouse::mineResources() {
    // TODO Petr
}

buildings::Resources buildings::LumberjackHouse::collectMinedResources() {
    int temp = m_minedWood;
    m_minedWood = 0;
    return Resources{temp, 0, 0};
}

void buildings::LumberjackHouse::printInfo() {
    // TODO Daniil
}

void buildings::LumberjackHouse::printHelp() {
    std::cout << "----- HELP OF LUMBERJACK_HOUSE -----" << std::endl;
    std::cout << "[0] - help" << std::endl;
    std::cout << "[1] - info about LumberjackHouse" << std::endl;
    std::cout << "[2] - will mine resources" << std::endl;
    std::cout << "------------------------------------" << std::endl;
}