//
// Created by Petr on 16.11.2021.
//

#ifndef ZOOPROJ_CHURCH_H
#define ZOOPROJ_CHURCH_H


#include "MoraleBuilding.h"

namespace buildings {
    /**
     * @brief A class representing a church
     *
     * Specific building of a church. Every church raises morale of village by 300.
     */
    class Church : public MoraleBuilding {
    public:
        /// Constructor for creating new churches
        Church(Coords coords, std::string name);

        void executeCommand(int command) override;

    private:
        void printInfo() override;

        void printHelp() override;
    };
}

#endif //ZOOPROJ_CHURCH_H
