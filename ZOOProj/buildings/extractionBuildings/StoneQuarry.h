//
// Created by Petr on 16.11.2021.
//

#ifndef ZOOPROJ_STONEQUARRY_H
#define ZOOPROJ_STONEQUARRY_H

#include "ExtractionBuilding.h"

namespace buildings {
    /**
     * @brief A class representing stone quarry.
     *
     * Every stone quarry can mine mountains and gather stone from them.
     * It can mine only neighbours, nothing else.
     * For each mined mountain, stone amount is increased by 150.
     * 200 of wood and 100 stone is required for building a lumberjack house.
     */
    class StoneQuarry : public ExtractionBuilding {
        /// amount of gathered stone
        int m_stoneAmount;
    public:
        /// Constructor creating new lumberjack house
        StoneQuarry(int coordX, int coordY, std::string name);

        /**
         * @brief Getter
         * @return amount of gathered stone
         */
        int getStoneAmount();

        /**
         * @return required amount of wood for building a stone quarry
         */
        static int getRequiredWood();

        /**
         * @return required amount of stone for building a stone quarry
         */
        static int getRequiredStone();

        /**
         * @return required amount of iron for building a stone quarry
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

#endif //ZOOPROJ_STONEQUARRY_H
