#include "Entity.h"

Entity::Entity(int coordX, int coordY, std::string appearance) {
    this->m_coordX = coordX;
    this->m_coordY = coordY;
    this->m_appearance = appearance;
}

int Entity::getCoordX() {
    return this->m_coordX;
}

int Entity::getCoordY() {
    return this->m_coordY;
}

std::string Entity::getAppearance() {
    return this->m_appearance;
}
