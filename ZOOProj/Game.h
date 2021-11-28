
#ifndef ZOOPROJ_GAME_H
#define ZOOPROJ_GAME_H


#include "World.h"

enum class GameResult {NONE, WIN, LOSE};

class Game {
private:
    static Game* s_instance;
    bool m_gameOver;
    GameResult m_gameResult;
    buildings::Building* m_proceededBuilding;
    World* m_world;

    Game();
    void initializeWorld(std::string title, int size);
    void commandCycle();
    void executeCommand(int command);
    void proceedToBuilding();
    void printHelp();

public:
    ~Game();
    static Game* getInstance();
    World* getWorld();
    void start();
    void end(GameResult result);
    void printInfoMessage(std::string message);
    void printInputMessage(std::string message);
    void printErrorMessage(std::string message);
};


#endif //ZOOPROJ_GAME_H
