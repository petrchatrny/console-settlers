//
// Created by Petr on 16.11.2021.
//

#ifndef ZOOPROJ_SWORDCRAFT_H
#define ZOOPROJ_SWORDCRAFT_H

#include "WeaponBuilding.h"

namespace buildings {
    /**
     * @brief A class representing sword craft.
     *
     * Every sword craft raises defence of village by 250.
     */
    class SwordCraft : public WeaponBuilding {
    public:
        /// Constructor creating new sword craft
        SwordCraft(Coords coords, std::string name);

        void executeCommand(int command) override;

    private:
        void printInfo() override;

        void printHelp() override;
    };
}

#endif //ZOOPROJ_SWORDCRAFT_H
