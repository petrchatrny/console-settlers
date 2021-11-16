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
     * 500 of wood and 150 stone and 500 of iron is required for building a bow craft.
     */
    class BowCraft : public WeaponBuilding {
    public:
        /// Constructor creating new sword craft
        BowCraft(int coordX, int coordY, std::string name);

        /**
         * @return required amount of wood for building a bow craft
         */
        static int getRequiredWood();

        /**
         * @return required amount of stone for building a bow craft
         */
        static int getRequiredStone();

        /**
         * @return required amount of iron for building a bow craft
         */
        static int getRequiredIron();

        void executeCommand(int command) override;

    private:
        void printInfo() override;

        void printHelp() override;
    };
}

#endif //ZOOPROJ_BOWCRAFT_H
