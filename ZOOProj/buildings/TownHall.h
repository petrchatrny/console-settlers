//
// Created by Petr on 15.11.2021.
//

#ifndef ZOOPROJ_TOWNHALL_H
#define ZOOPROJ_TOWNHALL_H

#include <vector>
#include "Building.h"

namespace buildings {
    enum BuildingType{
        HOUSE, COTTAGE,
        LUMBERJACK_HOUSE, STONE_QUARRY, IRON_MINE,
        THEATRE, CHURCH,
        SWORD_CRAFT, BOW_CRAFT
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
        /// Amount of wood currently available for building, set to 100 by default
        int m_woodAmount;

        /// Amount of stone currently available for building, set to 100 by default
        int m_stoneAmount;

        /// Amount of iron currently available for building, set to 100 by default
        int m_ironAmount;

        /// Collection of all built buildings except of town hall
        std::vector<Building*> m_buildings;

    public:
        /// Constructor for building new town hall
        TownHall(int coordX, int coordY, std::string name);

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
         *
         * @param type type of building
         * @param coordX x coordinate where the building should stand
         * @param coordY y coordinate where the building should stand
         * @param name name of building
         */
        void createNewBuilding(BuildingType type, int coordX, int coordY, std::string name);

        /**
         * @brief Method will try to transport resources from extraction building to town hall.
         *
         * @param coordX x coordinate of extraction building
         * @param coordY y coordinate of extraction building
         */
        void collectResourcesFromExtractionBuilding(int coordX, int coordY);
    };
}

#endif //ZOOPROJ_TOWNHALL_H
