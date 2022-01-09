//
// Created by Petr on 15.11.2021.
//

#ifndef ZOOPROJ_TOWNHALL_H
#define ZOOPROJ_TOWNHALL_H

#include <vector>
#include "populationBuildings/PopulationBuilding.h"
#include "extractionBuildings/ExtractionBuilding.h"
#include "weaponBuildings/WeaponBuilding.h"
#include "moraleBuildings/MoraleBuilding.h"
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

        /**
         * @brief Getter
         * @return vector of buildings in order : weaponBuildings, extractionBuildings, moraleBuildings, populationBuildings
         */
        std::vector<Building*> getMergedBuildings();

        /**
         * @brief The method will try to find building and remove it from townHall's vectors.
         * @param building pointer of building that should be removed from townHall
         */
        void destroyBuilding(Building* building);

        void executeCommand(int command) override;

    protected:
        void printInfo() override;

        void printHelp() override;

    private:
        /**
         * @brief The procedure will build a new building.
         *
         * Procedure first asks user to choose a building which will be created. Then it if will check if user has
         * enough resources for this building. If there are enough resources, user will be asked to enter name of the
         * building and coordinates where building should be created. After that, procedure will try to create building
         * in map let user know, if his attempt was successful or not.
         */
        void createNewBuilding();

        /**
         * @brief Procedure will try to transport resources from extraction building to town hall.
         *
         * Procedure first asks user to choose extraction building from which will be resources transported. Then it
         * will check if that building exists. If it does exist, resources will be transported from that building into
         * townHall and procedure will also try to invoke attack.
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

        /**
         * @brief Method will try to find building in vector and if building is found, it will remove building from
         * vector and update it.
         * @tparam T generic type
         * @param building pointer to destroyed building
         * @param vector vector of buildings
         * @return bool value if building was found and destroyed
         */
        template<typename T>
        bool destroyBuildingFromBuildingVector(Building* building, std::vector<T> &vector);
    };
}

#endif //ZOOPROJ_TOWNHALL_H
