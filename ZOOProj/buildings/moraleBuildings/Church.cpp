//
// Created by Petr on 16.11.2021.
//

#include "../../Game.h"
#include "Church.h"

buildings::Church::Church(Coords coords, std::string name)
        : MoraleBuilding(coords, name, "\U000026EA", 300) {

}

void buildings::Church::executeCommand(int command) {
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

void buildings::Church::printInfo() {
    std::cout << "Church{ x: " << getCoords().x << ", y: " << getCoords().y << ", name: " <<
    getName() << ", durability: " << getDurability() << " }" << std::endl;
}

void buildings::Church::printHelp() {
    std::cout << "----- HELP OF CHURCH -----" << std::endl;
    std::cout << "[0] - help" << std::endl;
    std::cout << "[1] - info about Church" << std::endl;
    std::cout << "[90] - will exit from the Church" << std::endl;
    std::cout << "--------------------------" << std::endl;
}
