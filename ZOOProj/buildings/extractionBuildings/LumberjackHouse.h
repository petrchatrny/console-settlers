//
// Created by Petr on 16.11.2021.
//

#ifndef ZOOPROJ_LUMBERJACKHOUSE_H
#define ZOOPROJ_LUMBERJACKHOUSE_H


#include "ExtractionBuilding.h"

namespace buildings {
    /**
     * @brief A class representing lumberjack house.
     *
     * Every lumberjack house can mine forests and gather wood from them.
     * It can mine only neighbours, nothing else.
     * For each mined forest, wood amount is increased by 150.
     * 100 of wood is required for building a lumberjack house.
     */
    class LumberjackHouse : public ExtractionBuilding {
        /// amount of gathered wood
        int m_woodAmount;
    public:
        /// Constructor creating new lumberjack house
        LumberjackHouse(int coordX, int coordY, std::string name);

        /**
         * @brief Getter
         * @return amount of gathered wood
         */
        int getWoodAmount();

        /**
         * @return required amount of wood for building a lumberjack house
         */
        static int getRequiredWood();

        /**
         * @return required amount of stone for building a lumberjack house
         */
        static int getRequiredStone();

        /**
         * @return required amount of iron for building a lumberjack house
         */
        static int getRequiredIron();

        void executeCommand(int command) override;

        void nullifyInventory() override;

    protected:
        void printInfo() override;

        void printHelp() override;

        void mineResources() override;
    };
}

#endif //ZOOPROJ_LUMBERJACKHOUSE_H
