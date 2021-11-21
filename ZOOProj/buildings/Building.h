//
// Created by Petr on 15.11.2021.
//

#ifndef ZOOPROJ_BUILDING_H
#define ZOOPROJ_BUILDING_H

#include <Entity.h>

namespace buildings {
    /**
     * @brief An abstract class representing a building that can be built on a map
     *
     * The class is used by inheritance for other more specific descendants.
     * It is just a general building.
     */
    class Building : public Entity {
        /// Name of building, which will be displayed in prompt when user will have the building proceeded.
        std::string m_name;

        /// Durability of building aka health. Set to 100 by default.
        float m_durability;

    protected:
        /// Protected constructor, because class Building is abstract.
        Building(int coordX, int coordY, std::string name, std::string appearance);

        /// Method will print information about building like name, durability,...
        virtual void printInfo() = 0;

        /// Method will print list of building's available commands
        virtual void printHelp() = 0;

    public:
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
    };
}

#endif //ZOOPROJ_BUILDING_H
