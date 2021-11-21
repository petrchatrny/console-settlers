//
// Created by Petr on 16.11.2021.
//

#ifndef ZOOPROJ_THEATRE_H
#define ZOOPROJ_THEATRE_H

#include "CultureBuilding.h"

namespace buildings {
    /**
     * @brief A class representing a theatre.
     *
     * Specific building of a theatre.
     * Every theatre raises morale of village by 150.
     * Cost of a theatre is 300 wood.
     */
    class Theatre : public CultureBuilding {
    public:
        /// Constructor for creating new churches
        Theatre(int coordX, int coordY, std::string name);

        /**
         * * @return required amount of wood to create a theatre
         * */
        static int getRequiredWoodAmount();

        /**
         * @return required amount of stone to create a theatre
         */
        static int getRequiredStoneAmount();

        /**
         * @return required amount of iron to create a theatre
         */
        static int getRequiredIronAmount();

        void executeCommand(int command) override;

    private:
        void printInfo() override;

        void printHelp() override;
    };
}

#endif //ZOOPROJ_THEATRE_H
