//
// Created by Petr on 15.11.2021.
//

#include "ExtractionBuilding.h"

buildings::ExtractionBuilding::ExtractionBuilding(Coords coords, std::string name, std::string appearance,
                                                  ResourceOutputType outputType)
        : Building(coords, name, appearance) {
    m_outputType = outputType;
}

buildings::ResourceOutputType buildings::ExtractionBuilding::getResourceOutputType() {
    return m_outputType;
}

