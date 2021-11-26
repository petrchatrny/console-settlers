//
// Created by Petr on 16.11.2021.
//

#ifndef ZOOPROJ_BOWCRAFT_H
#define ZOOPROJ_BOWCRAFT_H


#include "WeaponBuilding.h"

namespace buildings {
    /**
     * @brief A class representing bow craft.
     *
     * Every bow craft raises defence of village by 450.
     */
    class BowCraft : public WeaponBuilding {
    public:
        /// Constructor creating new sword craft
        BowCraft(Coords coords, std::string name);

        void executeCommand(int command) override;

    private:
        void printInfo() override;

        void printHelp() override;
    };
}

#endif //ZOOPROJ_BOWCRAFT_H
