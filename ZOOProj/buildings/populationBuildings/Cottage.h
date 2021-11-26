//
// Created by Petr on 16.11.2021.
//

#ifndef ZOOPROJ_COTTAGE_H
#define ZOOPROJ_COTTAGE_H

#include "PopulationBuilding.h"

namespace buildings {
    /**
     * @brief A class representing cottage.
     *
     * Every cottage is inhibited by 2 - 6 people.
     */
    class Cottage : public PopulationBuilding {
    public:
        /// Constructor creating new cottage
        Cottage(Coords coords, std::string name);

        void executeCommand(int command) override;

    protected:
        void printInfo() override;

        void printHelp() override;
    };
}

#endif //ZOOPROJ_COTTAGE_H
