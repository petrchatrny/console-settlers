//
// Created by Petr on 15.11.2021.
//

#include "MoraleBuilding.h"

buildings::MoraleBuilding::MoraleBuilding(Coords coords, std::string name, std::string appearance, int morale)
        : Building(coords, name, appearance) {
    m_morale = morale;
}

int buildings::MoraleBuilding::getMorale() {
    return m_morale;
}