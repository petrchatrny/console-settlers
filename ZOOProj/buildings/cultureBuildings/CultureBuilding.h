//
// Created by Petr on 15.11.2021.
//

#ifndef ZOOPROJ_CULTUREBUILDING_H
#define ZOOPROJ_CULTUREBUILDING_H

#include <buildings/Building.h>

namespace buildings {
    /**
     * @brief An abstract class representing culture building.
     *
     * The class is used by inheritance for other more specific descendants.
     * It is just a general culture building.
     * Culture buildings are raising morale of the village.
     * Higher morale will delay attack.
     */
    class CultureBuilding : public Building {
        /// Amount of morale which will building add.
        int m_morale;

    protected:
        /// Protected constructor, because class CultureBuilding is abstract.
        CultureBuilding(int coordX, int coordY, std::string name, std::string appearance, int morale);

    public:
        /**
         * @brief Getter
         * @return amount of morale
         */
        int getMorale();
    };
}


#endif //ZOOPROJ_CULTUREBUILDING_H
