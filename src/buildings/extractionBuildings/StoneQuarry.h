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
     */
    class StoneQuarry : public ExtractionBuilding {
        /// amount of mined stone
        int m_minedStone;
    public:
        /// Constructor creating new lumberjack house
        StoneQuarry(Coords coords, std::string name);

        void executeCommand(int command) override;

        Resources collectMinedResources() override;

    protected:
        void printInfo() override;

        void printHelp() override;

        void mineResources() override;
    };
}

#endif //ZOOPROJ_STONEQUARRY_H
