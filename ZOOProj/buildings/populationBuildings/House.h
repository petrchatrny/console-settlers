//
// Created by Petr on 16.11.2021.
//

#ifndef ZOOPROJ_HOUSE_H
#define ZOOPROJ_HOUSE_H

#include "PopulationBuilding.h"

namespace buildings {
    /**
     * @brief A class representing house.
     *
     * Every house inhabits from 6 to 12 people.
     * 100 of wood and 200 of stone is required for building a house.
     */
    class House : public PopulationBuilding {
    public:
        /// Constructor creating new house
        House(int coordX, int coordY, std::string name);

        /**
         * @return required amount of wood for building a house
         */
        static int getRequiredWood();

        /**
         * @return required amount of stone for building a house
         */
        static int getRequiredStone();

        /**
         * @return required amount of iron for building a house
         */
        static int getRequiredIron();

        void executeCommand(int command) override;

    protected:
        void printInfo() override;

        void printHelp() override;
    };
}

#endif //ZOOPROJ_HOUSE_H
