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
     */
    class House : public PopulationBuilding {
    public:
        /// Constructor creating new house
        House(Coords coords, std::string name);

        void executeCommand(int command) override;

    protected:
        void printInfo() override;

        void printHelp() override;
    };
}

#endif //ZOOPROJ_HOUSE_H
