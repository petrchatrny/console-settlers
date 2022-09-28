//
// Created by Petr on 16.11.2021.
//

#ifndef ZOOPROJ_THEATRE_H
#define ZOOPROJ_THEATRE_H

#include "MoraleBuilding.h"

namespace buildings {
    /**
     * @brief A class representing a theatre.
     *
     * Specific building of a theatre.
     * Every theatre raises morale of village by 150.
     */
    class Theatre : public MoraleBuilding {
    public:
        /// Constructor for creating new churches
        Theatre(Coords coords, std::string name);

        void executeCommand(int command) override;

    protected:
        void printInfo() override;

        void printHelp() override;
    };
}

#endif //ZOOPROJ_THEATRE_H
