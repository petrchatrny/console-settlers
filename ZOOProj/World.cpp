
#include "World.h"

World::World(std::string name, int size, int coordX, int coordY) {
    //TODO
    this->m_name = name;
}

std::string World::getName() {
    return this->m_name;
}

Map *World::getMap() {
    return this->m_map;
}
