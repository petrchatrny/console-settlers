//
// Created by xweiss3 on 11.11.2021.
//

#ifndef CV09_GAMEENGINE_H
#define CV09_GAMEENGINE_H

#include "ObjektovaHraciDeska.h"

class GameEngine {
private:
    ObjektovaHraciDeska *m_hraciDeska;
    void inicializujBunky();
    void vypisNapovedu();
public:
    GameEngine();
    void hraj();
    ~GameEngine();
};


#endif //CV09_GAMEENGINE_H
