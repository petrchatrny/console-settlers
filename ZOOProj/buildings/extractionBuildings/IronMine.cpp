//
// Created by Petr on 16.11.2021.
//

#include "IronMine.h"

buildings::IronMine::IronMine(int coordX, int coordY, std::string name)
        : ExtractionBuilding(coordX, coordY, name, "\U000026CF") {
    m_ironAmount = 0;
}

int buildings::IronMine::getIronAmount() {
    return m_ironAmount;
}

int buildings::IronMine::getRequiredWood() {
    return 200;
}

int buildings::IronMine::getRequiredStone() {
    return 200;
}

int buildings::IronMine::getRequiredIron() {
    return 100;
}

void buildings::IronMine::executeCommand(int command) {
    // TODO Petr
}

void buildings::IronMine::nullifyInventory() {
    m_ironAmount = 0;
}

void buildings::IronMine::printInfo() {
    // TODO Daniil
}

void buildings::IronMine::printHelp() {
    // TODO Daniil
}

void buildings::IronMine::mineResources() {
    // TODO Petr
}
