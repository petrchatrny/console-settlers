//
// Created by Petr on 16.11.2021.
//

#ifndef ZOOPROJ_WEAPONBUILDING_H
#define ZOOPROJ_WEAPONBUILDING_H

#include "../Building.h"
#include <iostream>
namespace buildings {
    /**
     * @brief An abstract class representing building with weapons.
     *
     * The class is used by inheritance for other more specific descendants. It is general building with weapons.
     * Weapon buildings raises village's defence to protect itself from attacks.
     */
    class WeaponBuilding : public Building {
        /// amount of defence which will be added to village
        int m_defence;

    protected:
        /// Protected constructor, because class WeaponBuilding is abstract.
        WeaponBuilding(Coords coords, std::string name, std::string appearance, int defence);

    public:
        /**
         * @brief Getter
         * @return amount of defence for village
         */
        int getDefence();
    };
}

#endif //ZOOPROJ_WEAPONBUILDING_H
