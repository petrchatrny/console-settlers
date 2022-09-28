//
// Created by Petr on 16.11.2021.
//

#include "../../Game.h"
#include "BowCraft.h"

buildings::BowCraft::BowCraft(Coords coords, std::string name)
        : WeaponBuilding(coords, name, "\U0001F3F9", 450) {
    // empty constructor
}

void buildings::BowCraft::executeCommand(int command) {
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

void buildings::BowCraft::printInfo() {
    std::cout << "Bow craft{ x: " << getCoords().x << ", y: " << getCoords().y << ", name: " <<
    getName() << ", durability: " << getDurability() << " }" << std::endl;
}

void buildings::BowCraft::printHelp() {
    std::cout << "----- HELP OF BOW_CRAFT -----" << std::endl;
    std::cout << "[0] - help" << std::endl;
    std::cout << "[1] - info about BowCraft" << std::endl;
    std::cout << "[90] - will exit from the BowCraft" << std::endl;
    std::cout << "-----------------------------" << std::endl;
}
