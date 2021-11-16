//
// Created by Petr on 15.11.2021.
//

#include "CultureBuilding.h"

buildings::CultureBuilding::CultureBuilding(int coordX, int coordY, std::string name, std::string appearance,
                                            int morale)
        : Building(coordX, coordY, name, appearance) {
    m_morale = morale;
}

int buildings::CultureBuilding::getMorale() {
    return m_morale;
}