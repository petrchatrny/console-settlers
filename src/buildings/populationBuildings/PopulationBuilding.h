//
// Created by Petr on 15.11.2021.
//

#ifndef ZOOPROJ_POPULATIONBUILDING_H
#define ZOOPROJ_POPULATIONBUILDING_H

#include "../Building.h"
#include <iostream>

namespace buildings {
    /**
     * @brief An abstract class representing inhabited building.
     *
     * The class is used by inheritance for other more specific descendants.
     * It is just a general inhabited building.
     */
    class PopulationBuilding : public Building {
        /// Population of the building
        int m_population;

    protected:
        /// Protected constructor, because class PopulationBuilding is abstract.
        PopulationBuilding(Coords coords, std::string name, std::string appearance, int population);

    public:
        /**
         * @brief Getter
         * @return population of the building
         */
        int getPopulation();
    };
}

#endif //ZOOPROJ_POPULATIONBUILDING_H
