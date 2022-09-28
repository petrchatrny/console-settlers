//
// Created by Petr on 15.11.2021.
//

#ifndef ZOOPROJ_BUILDING_H
#define ZOOPROJ_BUILDING_H

#include <string>

namespace buildings {
    /// x and y coordinates
    struct Coords {
        int x;
        int y;
    };

    /// types of buildings
    enum BuildingType {
        NONE,
        HOUSE, COTTAGE,
        THEATER, CHURCH,
        SWORD_CRAFT, BOW_CRAFT,
        LUMBERJACK_HOUSE, STONE_QUARRY, IRON_MINE
    };

    /// crate for Resources
    struct Resources {
        int wood;
        int stone;
        int iron;
    };

    /// types of resources which can be mined by extraction buildings
    enum ResourceOutputType {
        WOOD,
        STONE,
        IRON
    };

    /**
     * @brief An abstract class representing a building that can be built on a map
     *
     * The class is used by inheritance for other more specific descendants.
     * It is just a general building.
     */
    class Building {
        /// x and y coordinates of building in Map
        Coords m_coords;

        /// UNICODE emoji that will be displayed in console when printing a Map
        std::string m_appearance;

        /// Name of building, which will be displayed in prompt when user will have the building proceeded.
        std::string m_name;

        /// Durability of building aka health. Set to 100 by default.
        float m_durability;

    protected:
        /// Protected constructor, because class Building is abstract.
        Building(Coords coords, std::string name, std::string appearance);

        /// Method will print information about building like name, durability,...
        virtual void printInfo() = 0;

        /// Method will print list of building's available commands
        virtual void printHelp() = 0;

    public:
        /// public default destructor
        virtual ~Building() = default;

        /**
         * @brief Getter
         * @return coords of building
         */
        Coords getCoords();

        /**
         * @brief Getter
         * @return appearance of building
         */
        std::string getAppearance();

        /**
         * @brief Getter
         * @return name of building
         */
        std::string getName();

        /**
         * @brief Getter
         * @return durability of building
         */
        float getDurability();

        /**
         * @brief Method will deal damage to building.
         *
         * Method will subtract damage from current building's durability.
         * If damage is higher than durability, durability will be set to 0.
         *
         * @param damage the value of the damage that will be dealt
         */
        void takeDamage(float damage);

        /**
         * @brief A method that calls another method based on the command number.
         * @param command number value of command, which should be executed
         */
        virtual void executeCommand(int command) = 0;

        static BuildingType convertIntToBuildingType(int value);
    };
}

#endif //ZOOPROJ_BUILDING_H
