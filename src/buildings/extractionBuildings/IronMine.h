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
     */
    class IronMine : public ExtractionBuilding {
        /// amount of mined iron
        int m_minedIron;

    public:
        /// Constructor creating new lumberjack house
        IronMine(Coords coords, std::string name);

        void executeCommand(int command) override;

        Resources collectMinedResources() override;

    protected:
        void printInfo() override;

        void printHelp() override;

        void mineResources() override;
    };
}

#endif //ZOOPROJ_IRONMINE_H
