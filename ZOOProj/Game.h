
#ifndef ZOOPROJ_GAME_H
#define ZOOPROJ_GAME_H


#include "World.h"

class Game {
private:
    bool m_gameOver = false;
    World* m_world;
    Game();
    ~Game();
    void initializeWorld();
    void commandCycle();
    void proceedToBuilding(int coordX, int coordY);
    void printHelp();

public:
    Game* getInstance();
    World* getWorld();
    void start();
};


#endif //ZOOPROJ_GAME_H
