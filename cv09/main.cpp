#include <iostream>
#include "GameEngine.h"

int main() {
    GameEngine* hra = new GameEngine();
    hra->hraj();
    delete hra;
    return 0;
}
