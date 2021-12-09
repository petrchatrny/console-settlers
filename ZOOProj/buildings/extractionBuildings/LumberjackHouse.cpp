//
// Created by Petr on 16.11.2021.
//

#include "../../Game.h"
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
        case 90:
            Game::getInstance()->quitTheBuilding();
            break;
        default:
            break;
    }
}

void buildings::LumberjackHouse::mineResources() {
    Coords coords = getCoords();
    std::vector<Resources> resources = {};

    // up
    if (coords.x - 1 >= 0) {
        resources.push_back(Game::getInstance()->getWorld()->getMap()->mineTerrain({coords.x - 1, coords.y}, this));
    }

    // down
    if (coords.x + 1 <= Game::getInstance()->getWorld()->getMap()->getSize() - 1) {
        resources.push_back(Game::getInstance()->getWorld()->getMap()->mineTerrain({coords.x + 1, coords.y}, this));
    }

    // left
    if (coords.y - 1 >= 0) {
        resources.push_back(Game::getInstance()->getWorld()->getMap()->mineTerrain({coords.x, coords.y - 1}, this));
    }

    // right
    if (coords.y + 1 <= Game::getInstance()->getWorld()->getMap()->getSize() - 1) {
        resources.push_back(Game::getInstance()->getWorld()->getMap()->mineTerrain({coords.x, coords.y + 1}, this));
    }

    for (Resources res: resources) {
        m_minedWood += res.wood;
    }

    Game::getInstance()->printMessage("Mining done", INFO);
}

buildings::Resources buildings::LumberjackHouse::collectMinedResources() {
    int temp = m_minedWood;
    m_minedWood = 0;
    return Resources{temp, 0, 0};
}

void buildings::LumberjackHouse::printInfo() {
    std::cout << "LumberjackHouse{ x: " << getCoords().x << ", y: " << getCoords().y << ", name: " <<
    getName() << ", durability: " << getDurability() << ", mined wood: " << m_minedWood << " }" << std::endl;
}

void buildings::LumberjackHouse::printHelp() {
    std::cout << "----- HELP OF LUMBERJACK_HOUSE -----" << std::endl;
    std::cout << "[0] - help" << std::endl;
    std::cout << "[1] - info about LumberjackHouse" << std::endl;
    std::cout << "[2] - will mine resources" << std::endl;
    std::cout << "[90] - will exit from the LumberjackHouse" << std::endl;
    std::cout << "------------------------------------" << std::endl;
}