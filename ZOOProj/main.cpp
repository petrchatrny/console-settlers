#include <iostream>
#include "Game.h"

int main() {
    Game* game;
    game->start();
    delete game;
    return 0;
}
