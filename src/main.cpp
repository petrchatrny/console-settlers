#include <iostream>
#include "Game.h"

int main() {
    Game* game = Game::getInstance();
    game->start();

    std::cout << std::endl << "Press enter to exit game";
    std::cin;
    return 0;
}
