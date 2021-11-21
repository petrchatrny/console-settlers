
#ifndef ZOOPROJ_GAME_H
#define ZOOPROJ_GAME_H


#include "World.h"

enum class GameResult {NONE, WIN, LOSE};

class Game {
private:
    bool m_gameOver = false;
    GameResult m_gameResult = GameResult::NONE;
    //TODO Building proceededBuilding;
    World* m_world;
    //TODO Game instance
    Game();
    ~Game();
    void initializeWorld(std::string title, int size);
    void commandCycle();
    void proceedToBuilding(int coordX, int coordY);
    void printHelp();

public:
    Game* getInstance();
    World* getWorld();
    void start();
};


#endif //ZOOPROJ_GAME_H
