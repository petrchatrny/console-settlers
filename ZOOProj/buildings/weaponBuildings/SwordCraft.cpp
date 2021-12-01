//
// Created by Petr on 16.11.2021.
//

#include "../../Game.h"
#include "SwordCraft.h"

buildings::SwordCraft::SwordCraft(Coords coords, std::string name)
        : WeaponBuilding(coords, name, "\U00002694", 250) {
    // empty constructor
}

void buildings::SwordCraft::executeCommand(int command) {
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

void buildings::SwordCraft::printInfo() {
    std::cout << "Sword craft{ x: " << getCoords().x << ", y: " << getCoords().y << ", name: " <<
    getName() << ", durability: " << getDurability() << " }" << std::endl;
}

void buildings::SwordCraft::printHelp() {
    std::cout << "----- HELP OF SWORD_CRAFT -----" << std::endl;
    std::cout << "[0] - help" << std::endl;
    std::cout << "[1] - info about SwordCraft" << std::endl;
    std::cout << "[90] - will exit from the SwordCraft" << std::endl;
    std::cout << "-------------------------------" << std::endl;
}