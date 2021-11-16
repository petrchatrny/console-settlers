//
// Created by Petr on 16.11.2021.
//

#include "StoneQuarry.h"

buildings::StoneQuarry::StoneQuarry(int coordX, int coordY, std::string name)
        : ExtractionBuilding(coordX, coordY, name, "\U00002692") {
    m_stoneAmount = 0;
}

int buildings::StoneQuarry::getStoneAmount() {
    return m_stoneAmount;
}

int buildings::StoneQuarry::getRequiredWood() {
    return 200;
}

int buildings::StoneQuarry::getRequiredStone() {
    return 100;
}

int buildings::StoneQuarry::getRequiredIron() {
    return 0;
}

void buildings::StoneQuarry::executeCommand(int command) {
    // TODO Petr
}

void buildings::StoneQuarry::nullifyInventory() {
    m_stoneAmount = 0;
}

void buildings::StoneQuarry::printInfo() {
    // TODO Daniil
}

void buildings::StoneQuarry::printHelp() {
    // TODO Daniil
}

void buildings::StoneQuarry::mineResources() {
    // TODO Petr
}
