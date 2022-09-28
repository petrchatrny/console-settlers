//
// Created by Petr on 16.11.2021.
//

#include "../../Game.h"
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
        case 90:
            Game::getInstance()->quitTheBuilding();
            break;
        default:
            break;
    }
}

void buildings::StoneQuarry::mineResources() {
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
        m_minedStone += res.stone;
    }

    Game::getInstance()->printMessage("Mining done", INFO);
}

buildings::Resources buildings::StoneQuarry::collectMinedResources() {
    int temp = m_minedStone;
    m_minedStone = 0;
    return Resources{0, temp, 0};
}

void buildings::StoneQuarry::printInfo() {
    std::cout << "Stone quarry{ x: " << getCoords().x << ", y: " << getCoords().y << ", name: " <<
    getName() << ", durability: " << getDurability() << ", mined stone: " << m_minedStone << " }" << std::endl;
}

void buildings::StoneQuarry::printHelp() {
    std::cout << "----- HELP OF STONE_QUARRY -----" << std::endl;
    std::cout << "[0] - help" << std::endl;
    std::cout << "[1] - info about StoneQuarry" << std::endl;
    std::cout << "[2] - will mine resources" << std::endl;
    std::cout << "[90] - will exit from the StoneQuarry" << std::endl;
    std::cout << "--------------------------------" << std::endl;
}
