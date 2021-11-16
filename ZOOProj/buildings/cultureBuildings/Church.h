//
// Created by Petr on 16.11.2021.
//

#ifndef ZOOPROJ_CHURCH_H
#define ZOOPROJ_CHURCH_H


#include "CultureBuilding.h"

namespace buildings {
/**
  * @brief A class representing a church
  *
  * Specific building of a church. Every church raises morale of village by 300.
  * Cost of a church is 200 wood and 350 stone.
  */
    class Church : public CultureBuilding {
    public:
        /// Constructor for creating new churches
        Church(int coordX, int coordY, std::string name);

        /**
         * * @return required amount of wood to create a church
         * */
        static int getRequiredWoodAmount();

        /**
         * @return required amount of stone to create a church
         */
        static int getRequiredStoneAmount();

        /**
         * @return required amount of iron to create a church
         */
        static int getRequiredIronAmount();

        void executeCommand(int command) override;

    private:
        void printInfo() override;

        void printHelp() override;
    };
}

#endif //ZOOPROJ_CHURCH_H
