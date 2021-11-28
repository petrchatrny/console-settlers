#include <iostream>
#include "Game.h"

int main() {
    Game* game = Game::getInstance();
    game->start();

    return 0;
}
