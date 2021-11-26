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
    BuildingCost cost = BuildingCost{};
    switch (type) {
        case HOUSE:
            cost = BuildingCost{100, 200, 0};
            break;
        case COTTAGE:
            cost = BuildingCost{150, 0, 0};
            break;
        case THEATER:
            cost = BuildingCost{300, 0, 0};
            break;
        case CHURCH:
            cost = BuildingCost{200, 350, 0};
            break;
        case SWORD_CRAFT:
            cost = BuildingCost{400, 100, 300};
            break;
        case BOW_CRAFT:
            cost = BuildingCost{500, 150, 500};
            break;
        case LUMBERJACK_HOUSE:
            cost = BuildingCost{100, 0, 0};
            break;
        case STONE_QUARRY:
            cost = BuildingCost{150, 100, 0};
            break;
        case IRON_MINE:
            cost = BuildingCost{200, 150, 100};
            break;
    }
    return cost;
}
