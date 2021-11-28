//
// Created by Petr on 15.11.2021.
//

#include <iostream>
#include "../Game.h"
#include "populationBuildings/House.h"
#include "populationBuildings/Cottage.h"
#include "moraleBuildings/Theatre.h"
#include "moraleBuildings/Church.h"
#include "weaponBuildings/SwordCraft.h"
#include "weaponBuildings/BowCraft.h"
#include "extractionBuildings/LumberjackHouse.h"
#include "extractionBuildings/StoneQuarry.h"
#include "extractionBuildings/IronMine.h"
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
    for (PopulationBuilding* pb : m_populationBuildings) {
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
    int buildingTypeCode;
    Coords coords = Coords{};
    std::string buildingName;

    // get buildingType
    Game::getInstance()->printInputMessage(
            "Choose type of building to create - House (0); Cottage (1); Theatre (2); Church (3); Sword craft (4); Bow craft (5); Lumberjack house (6); Stone quarry (7); Iron mine (8)");
    std::cin >> buildingTypeCode;

    // convert int to BuildingType
    BuildingType buildingType = Building::convertIntToBuildingType(buildingTypeCode);

    // check resources
    if (!enoughResourcesToBuild(buildingType)) {
        Game::getInstance()->printErrorMessage("You don't have enough resources for creating this building");
        return;
    }

    // get building name
    Game::getInstance()->printInputMessage("Enter building's name: ");
    std::cin >> buildingName;

    // get coords
    Game::getInstance()->printInputMessage("Enter the coords where you want to build the building (x y): ");
    std::cin >> coords.x >> coords.y;

    // check coords
    bool success;
    switch (buildingType) {
        case HOUSE:
            House* house;
            house = new House(coords, buildingName);
            success = Game::getInstance()->getWorld()->getMap()->createBuilding(coords, house);
            if (success) {
                m_populationBuildings.push_back(house);
            } else {
                delete house;
            }
            break;
        case COTTAGE:
            Cottage* cottage;
            cottage = new Cottage(coords, buildingName);
            success = Game::getInstance()->getWorld()->getMap()->createBuilding(coords, cottage);
            if (success) {
                m_populationBuildings.push_back(cottage);
            } else {
                delete cottage;
            }
            break;
        case THEATER:
            Theatre* theatre;
            theatre = new Theatre(coords, buildingName);
            success = Game::getInstance()->getWorld()->getMap()->createBuilding(coords, theatre);
            if (success) {
                m_moraleBuildings.push_back(theatre);
            } else {
                delete theatre;
            }
            break;
        case CHURCH:
            Church* church;
            church = new Church(coords, buildingName);
            success = Game::getInstance()->getWorld()->getMap()->createBuilding(coords, church);
            if (success) {
                m_moraleBuildings.push_back(church);
            } else {
                delete church;
            }
            break;
        case SWORD_CRAFT:
            SwordCraft* swordCraft;
            swordCraft = new SwordCraft(coords, buildingName);
            success = Game::getInstance()->getWorld()->getMap()->createBuilding(coords, swordCraft);
            if (success) {
                m_weaponBuildings.push_back(swordCraft);
            } else {
                delete swordCraft;
            }
            break;
        case BOW_CRAFT:
            BowCraft* bowCraft;
            bowCraft = new BowCraft(coords, buildingName);
            success = Game::getInstance()->getWorld()->getMap()->createBuilding(coords, bowCraft);
            if (success) {
                m_weaponBuildings.push_back(bowCraft);
            } else {
                delete bowCraft;
            }
            break;
        case LUMBERJACK_HOUSE:
            LumberjackHouse* lumberjackHouse;
            lumberjackHouse = new LumberjackHouse(coords, buildingName);
            success = Game::getInstance()->getWorld()->getMap()->createBuilding(coords, lumberjackHouse);
            if (success) {
                m_extractionBuildings.push_back(lumberjackHouse);
            } else {
                delete lumberjackHouse;
            }
            break;
        case STONE_QUARRY:
            StoneQuarry* stoneQuarry;
            stoneQuarry = new StoneQuarry(coords, buildingName);
            success = Game::getInstance()->getWorld()->getMap()->createBuilding(coords, stoneQuarry);
            if (success) {
                m_extractionBuildings.push_back(stoneQuarry);
            } else {
                delete stoneQuarry;
            }
            break;
        case IRON_MINE:
            IronMine* ironMine;
            ironMine = new IronMine(coords, buildingName);
            success = Game::getInstance()->getWorld()->getMap()->createBuilding(coords, ironMine);
            if (success) {
                m_extractionBuildings.push_back(ironMine);
            } else {
                delete ironMine;
            }
            break;
        case NONE:
            Game::getInstance()->printErrorMessage("You chose wrong building type");
            success = false;
            break;
    }

    // check output of createBuilding()
    if (success) {
        Game::getInstance()->printInfoMessage("Building created");

        // consume resources
        BuildingCost cost = getBuildingCost(buildingType);
        m_resources.wood -= cost.requiredWood;
        m_resources.stone -= cost.requiredStone;
        m_resources.iron -= cost.requiredIron;
    } else {
        Game::getInstance()->printErrorMessage("Couldn't create the building");
    }
}

void buildings::TownHall::collectResourcesFromExtractionBuilding() {
    Coords coords = Coords{};
    bool success = false;

    // get coords
    Game::getInstance()->printInputMessage(
            "Enter coords of extraction building from which you want to extract resources (x y):");
    std::cin >> coords.x >> coords.y;

    // find ExtractionBuilding and collect resources
    for (ExtractionBuilding* eb : m_extractionBuildings) {
        if (eb->getCoords().x == coords.x && eb->getCoords().y == coords.y) {
            Resources res = eb->collectMinedResources();
            m_resources.wood += res.wood;
            m_resources.stone += res.stone;
            m_resources.iron += res.iron;
            success = true;
        }
    }
    // inform user
    if (success) {
        Game::getInstance()->printInfoMessage("Resources were extracted");
        Game::getInstance()->getWorld()->tryToInvokeAttack();
    } else {
        Game::getInstance()->printErrorMessage("A mining building with these coordinates could not be found");
    }
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
        case 90:
            Game::getInstance()->quitTheBuilding();
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
    return m_resources.wood >= cost.requiredWood && m_resources.stone >= cost.requiredStone &&
           m_resources.iron >= cost.requiredIron;
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
        case NONE:
            cost = BuildingCost{0, 0, 0};
            break;
    }
    return cost;
}

std::vector<buildings::PopulationBuilding *> buildings::TownHall::getPopulationBuildings() {
    return m_populationBuildings;
}

std::vector<buildings::MoraleBuilding *> buildings::TownHall::getMoraleBuildings() {
    return m_moraleBuildings;
}

std::vector<buildings::WeaponBuilding *> buildings::TownHall::getWeaponBuildings() {
    return m_weaponBuildings;
}

std::vector<buildings::ExtractionBuilding *> buildings::TownHall::getExtractionBuildings() {
    return m_extractionBuildings;
}
