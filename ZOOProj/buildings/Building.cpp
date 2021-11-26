//
// Created by Petr on 26.11.2021.
//

#include "Building.h"

buildings::Building::Building(Coords coords, std::string name, std::string appearance) {
    m_coords = coords;
    m_appearance = appearance;
    m_name = name;
    m_durability = 100;
}

buildings::Coords buildings::Building::getCoords() {
    return m_coords;
}

std::string buildings::Building::getAppearance() {
    return m_appearance;
}

std::string buildings::Building::getName() {
    return m_name;
}

float buildings::Building::getDurability() {
    return m_durability;
}

void buildings::Building::takeDamage(float damage) {
    m_durability -= damage;
}