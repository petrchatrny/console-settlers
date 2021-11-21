#ifndef ZOOPROJ_TERRAIN_H
#define ZOOPROJ_TERRAIN_H


#include "../Entity.h"

class Terrain: public Entity {
public:
    Terrain(int coordX, int coordY, std::string appearance);
};


#endif //ZOOPROJ_TERRAIN_H
