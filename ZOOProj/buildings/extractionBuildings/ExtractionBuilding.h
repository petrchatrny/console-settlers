//
// Created by Petr on 15.11.2021.
//

#ifndef ZOOPROJ_EXTRACTIONBUILDING_H
#define ZOOPROJ_EXTRACTIONBUILDING_H

#include <buildings/Building.h>

namespace buildings {
    /**
     * @brief An abstract class representing extraction building.
     *
     * The class is used by inheritance for other more specific descendants.
     * It is just a general extraction building.
     * Extraction buildings are used for mining terrain and gathering resources.
     * After mining are resources stored in descendant's inventory.
     * Town hall is able to transport resources to itself.
     */
    class ExtractionBuilding : public Building {
    protected:
        /// Protected constructor, because class Building is abstract.
        ExtractionBuilding(int coordX, int coordY, std::string name, std::string appearance);

        /**
         * @brief The method mine the terrain around the descendant.
         *
         * Extracted resources are stored in the descendant's inventory
         */
        virtual void mineResources() = 0;

    public:
        /// The method empties descendant's inventory
        virtual void nullifyInventory() = 0;
    };
}

#endif //ZOOPROJ_EXTRACTIONBUILDING_H
