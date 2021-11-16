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
     * 300 of wood and 200 stone and 300 of iron is required for building a sword craft.
     */
    class SwordCraft : public WeaponBuilding {
    public:
        /// Constructor creating new sword craft
        SwordCraft(int coordX, int coordY, std::string name);

        /**
         * @return required amount of wood for building a sword craft
         */
        static int getRequiredWood();

        /**
         * @return required amount of stone for building a sword craft
         */
        static int getRequiredStone();

        /**
         * @return required amount of iron for building a sword craft
         */
        static int getRequiredIron();

        void executeCommand(int command) override;

    private:
        void printInfo() override;

        void printHelp() override;
    };
}

#endif //ZOOPROJ_SWORDCRAFT_H
