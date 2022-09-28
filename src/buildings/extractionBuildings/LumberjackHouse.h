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
     */
    class LumberjackHouse : public ExtractionBuilding {
        /// amount of mined wood
        int m_minedWood;
    public:
        /// Constructor creating new lumberjack house
        LumberjackHouse(Coords coords, std::string name);

        void executeCommand(int command) override;

        Resources collectMinedResources() override;

    protected:
        void printInfo() override;

        void printHelp() override;

        void mineResources() override;
    };
}

#endif //ZOOPROJ_LUMBERJACKHOUSE_H
