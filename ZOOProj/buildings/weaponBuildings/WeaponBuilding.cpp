//
// Created by Petr on 16.11.2021.
//

#include "WeaponBuilding.h"

buildings::WeaponBuilding::WeaponBuilding(int coordX, int coordY, std::string name, std::string appearance, int defence)
        : Building(coordX, coordY, name, appearance) {
    m_defence = defence;
}

int buildings::WeaponBuilding::getDefence() {
    return m_defence;
}
