//
// Created by Petr on 15.11.2021.
//

#ifndef ZOOPROJ_TOWNHALL_H
#define ZOOPROJ_TOWNHALL_H

#include <vector>
#include <PopulationBuilding.h>
#include <ExtractionBuilding.h>
#include <WeaponBuilding.h>
#include <MoraleBuilding.h>
#include "Building.h"

namespace buildings {
    /// required resources to create building
    struct BuildingCost {
        int requiredWood;
        int requiredStone;
        int requiredIron;
    };

    /**
     * @brief A class representing town hall of the village.
     *
     * The most important building in the village.
     * It stores amount of available materials in it.
     * Other buildings can be built by this building.
     * Materials from extraction buildings can be transported to this building.
     * This building can also calculate total population, morale and defence.
     */
    class TownHall : public Building {
        /// Amount of resources currently available in TownHall, set to 100 for each resource type by default
        Resources m_resources;

        /// Collection of all built population buildings
        std::vector<PopulationBuilding *> m_populationBuildings;

        /// Collection of all built morale buildings
        std::vector<MoraleBuilding*> m_moraleBuildings;

        /// Collection of all built extraction buildings
        std::vector<ExtractionBuilding*> m_extractionBuildings;

        /// Collection of all built weapon buildings
        std::vector<WeaponBuilding*> m_weaponBuildings;

    public:
        /// Constructor for building new town hall
        TownHall(Coords coords, std::string name);

        /**
         * @brief The method calculates how many inhabitants are in the village in total.
         * @return total population count
         */
        int getTotalPopulation();

        /**
         * @brief The method will calculate how much morale village has from culture buildings.
         * @return total morale of village
         */
        int getTotalMorale();

        /**
         * @brief The method will calculate how much defence village has from weapon buildings.
         * @return total defence of village
         */
        int getTotalDefence();

        void executeCommand(int command) override;

    protected:
        void printInfo() override;

        void printHelp() override;

    private:
        /**
         * @brief The method will build a new building if the user has enough resources.
         */
        void createNewBuilding();

        /**
         * @brief Method will try to transport resources from extraction building to town hall.
         */
        void collectResourcesFromExtractionBuilding();

        /**
         * @brief Method will check if user has enough resources in town hall for creating specific building
         * @param type type of building
         * @return if user has enough resources to create building or not
         */
        bool enoughResourcesToBuild(BuildingType type);

        /**
         * @param type type of building
         * @return three numbers (BuildingCost) that represent the required amount of resources to create building
         */
        BuildingCost getBuildingCost(BuildingType type);
    };
}

#endif //ZOOPROJ_TOWNHALL_H
