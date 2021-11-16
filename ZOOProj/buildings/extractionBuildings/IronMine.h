//
// Created by Petr on 16.11.2021.
//

#ifndef ZOOPROJ_IRONMINE_H
#define ZOOPROJ_IRONMINE_H

#include "ExtractionBuilding.h"

namespace buildings {
    /**
     * @brief A class representing iron mine.
     *
     * Every iron mine can mine mountains and secret cave and gather iron from them.
     * It can mine only neighbours, nothing else.
     * For each mined mountain, iron amount is increased by 150.
     * 200 of wood and 200 stone and 100 of iron is required for building an iron mine.
     */
    class IronMine : ExtractionBuilding {
        /// amount of gathered iron
        int m_ironAmount;

    public:
        /// Constructor creating new lumberjack house
        IronMine(int coordX, int coordY, std::string name);

        /**
         * @brief Getter
         * @return amount of gathered stone
         */
        int getIronAmount();

        /**
         * @return required amount of wood for building an iron mine
         */
        static int getRequiredWood();

        /**
         * @return required amount of stone for building a iron mine
         */
        static int getRequiredStone();

        /**
         * @return required amount of iron for building an iron mine
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

#endif //ZOOPROJ_IRONMINE_H
