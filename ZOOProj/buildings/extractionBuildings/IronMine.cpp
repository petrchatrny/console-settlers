//
// Created by Petr on 16.11.2021.
//

#include "../../Game.h"
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
        case 90:
            Game::getInstance()->quitTheBuilding();
            break;
        default:
            break;
    }
}

void buildings::IronMine::mineResources() {
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
        m_minedIron += res.iron;
    }

    Game::getInstance()->printMessage("Mining done", INFO);
}

buildings::Resources buildings::IronMine::collectMinedResources() {
    int temp = m_minedIron;
    m_minedIron = 0;
    return Resources{0, 0, temp};
}

void buildings::IronMine::printInfo() {
    std::cout << "Iron mine{ x: " << getCoords().x << ", y: " << getCoords().y << ", name: " <<
    getName() << ", durability: " << getDurability() << ", mined iron: " << m_minedIron << " }" << std::endl;
}

void buildings::IronMine::printHelp() {
    std::cout << "----- HELP OF IRON_MINE -----" << std::endl;
    std::cout << "[0] - help" << std::endl;
    std::cout << "[1] - info about IronMine" << std::endl;
    std::cout << "[2] - will mine resources" << std::endl;
    std::cout << "[90] - will exit from the IronMine" << std::endl;
    std::cout << "-----------------------------" << std::endl;
}
