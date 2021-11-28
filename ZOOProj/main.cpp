#include <iostream>
#include "Game.h"

int main() {
    Game* game = Game::getInstance();
    game->start();

    delete game;
    return 0;
}
