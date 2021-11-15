//
// Created by Petr on 15.11.2021.
//

#include "Building.h"

buildings::Building::Building(int coordX, int coordY, std::string name, std::string appearance)
        : Entity(coordX, coordY, appearance) {
}

std::string buildings::Building::getName() {
    return std::__cxx11::string();
}

float buildings::Building::getDurability() {
    return 0;
}

void buildings::Building::takeDamage(float damage) {

}