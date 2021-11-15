//
// Created by Petr on 15.11.2021.
//

#include "Building.h"

buildings::Building::Building(int coordX, int coordY, std::string name, std::string appearance)
        : Entity(coordX, coordY, appearance) {
    m_name = name;
    m_durability = 100;
}

std::string buildings::Building::getName() {
    return m_name;
}

float buildings::Building::getDurability() {
    return m_durability;
}

void buildings::Building::takeDamage(float damage) {
    if (damage > m_durability) {
        m_durability = 0;
    } else {
        m_durability -= damage;
    }
}