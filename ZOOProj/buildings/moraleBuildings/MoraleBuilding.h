//
// Created by Petr on 15.11.2021.
//

#ifndef ZOOPROJ_CULTUREBUILDING_H
#define ZOOPROJ_CULTUREBUILDING_H

#include "../Building.h"
#include <iostream>

namespace buildings {
    /**
     * @brief An abstract class representing morale building.
     *
     * The class is used by inheritance for other more specific descendants.
     * It is just a general morale building.
     * Morale buildings are raising morale of the village.
     * Higher morale will delay attack.
     */
    class MoraleBuilding : public Building {
        /// Amount of morale which will building add.
        int m_morale;

    protected:
        /// Protected constructor, because class MoraleBuilding is abstract.
        MoraleBuilding(Coords coords, std::string name, std::string appearance, int morale);

    public:
        /**
         * @brief Getter
         * @return amount of morale
         */
        int getMorale();
    };
}


#endif //ZOOPROJ_CULTUREBUILDING_H
