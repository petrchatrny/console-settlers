//
// Created by Petr on 15.11.2021.
//

#include "TownHall.h"

buildings::TownHall::TownHall(Coords coords, std::string name)
        : Building(coords, name, "\U0001F3DB") {
    m_resources = Resources{100, 100, 100};
    m_populationBuildings = {};
    m_moraleBuildings = {};
    m_weaponBuildings = {};
    m_extractionBuildings = {};
}

int buildings::TownHall::getTotalPopulation() {
    int sum = 0;
    for (PopulationBuilding *pb: m_populationBuildings) {
        sum += pb->getPopulation();
    }
    return sum;
}

int buildings::TownHall::getTotalMorale() {
    int sum = 0;
    for (MoraleBuilding* mb: m_moraleBuildings) {
        sum += mb->getMorale();
    }
    return sum;
}

int buildings::TownHall::getTotalDefence() {
    int sum = 0;
    for (WeaponBuilding* wb: m_weaponBuildings) {
        sum += wb->getDefence();
    }
    return sum;
}

void buildings::TownHall::createNewBuilding() {
    // TODO Petr
}

void buildings::TownHall::collectResourcesFromExtractionBuilding() {
    // TODO Petr
}

void buildings::TownHall::executeCommand(int command) {
    switch (command) {
        case 0:
            printHelp();
            break;
        case 1:
            printInfo();
            break;
        case 2:
            createNewBuilding();
            break;
        case 3:
            collectResourcesFromExtractionBuilding();
            break;
        default:
            break;
    }
}

void buildings::TownHall::printInfo() {
    // TODO Daniil
}

void buildings::TownHall::printHelp() {
    // TODO Daniil
}

bool buildings::TownHall::enoughResourcesToBuild(buildings::BuildingType type) {
    BuildingCost cost = getBuildingCost(type);
    return cost.requiredWood >= m_resources.wood && cost.requiredStone >= m_resources.stone &&
           cost.requiredIron >= m_resources.iron;
}

buildings::BuildingCost buildings::TownHall::getBuildingCost(buildings::BuildingType type) {
    switch (type) {
        case HOUSE:
            return BuildingCost{100, 200, 0};
        case COTTAGE:
            return BuildingCost{150, 0, 0};
        case THEATER:
            return BuildingCost{300, 0, 0};
        case CHURCH:
            return BuildingCost{200, 350, 0};
        case SWORD_CRAFT:
            return BuildingCost{400, 100, 300};
        case BOW_CRAFT:
            return BuildingCost{500, 150, 500};
        case LUMBERJACK_HOUSE:
            return BuildingCost{100, 0, 0};
        case STONE_QUARRY:
            return BuildingCost{150, 100, 0};
        case IRON_MINE:
            return BuildingCost{200, 150, 100};
    }
}
