
#ifndef ZOOPROJ_GAME_H
#define ZOOPROJ_GAME_H


#include "World.h"

enum class GameResult {WIN, LOSE};

enum MessageType {
    INFO,
    INPUT,
    ERROR
};

class Game {
private:
    static Game* s_instance;
    bool m_gameOver;
    buildings::Building* m_activeBuilding;
    World* m_world;

    Game();
    void initializeWorld(std::string title, int size);
    int processInput(std::string input);
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
    void printMessage(std::string message, MessageType type);
};


#endif //ZOOPROJ_GAME_H
