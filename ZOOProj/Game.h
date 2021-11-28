
#ifndef ZOOPROJ_GAME_H
#define ZOOPROJ_GAME_H


#include "World.h"

enum class GameResult {WIN, LOSE};

class Game {
private:
    static Game* s_instance;
    bool m_gameOver;
    buildings::Building* m_activeBuilding;
    World* m_world;

    Game();
    void initializeWorld(std::string title, int size);
    void commandCycle();
    void executeCommand(int command);
    void enterTheBuilding();
    void printHelp();

public:
    ~Game();
    static Game* getInstance();
    World* getWorld();
    void start();
    void end(GameResult result);
    void quitTheBuilding();
    void printInfoMessage(std::string message);
    void printInputMessage(std::string message);
    void printErrorMessage(std::string message);
};


#endif //ZOOPROJ_GAME_H
