//
// Created by Petr on 15.11.2021.
//

#include "PopulationBuilding.h"

buildings::PopulationBuilding::PopulationBuilding(Coords coords, std::string name, std::string appearance, int population)
        : Building(coords, name, appearance) {
    m_population = population;
}

int buildings::PopulationBuilding::getPopulation() {
    return m_population;
}
