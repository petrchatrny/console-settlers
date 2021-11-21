
#include <iostream>
#include "Game.h"

World *Game::getWorld() {
    return this->m_world;
}

void Game::initializeWorld(std::string title, int size) {
    this->m_world = new World(title, size);
}

void Game::start() {
    std::string title;
    int worldsize;
    std::cout << "Zadej nazev sveta: ";
    std::cin >> title;
    std::cout << "Zvol velikost sveta (1) 6x6, (2) 8x8, (3) 12x12: ";
    std::cin >> worldsize;
    std::cout << std::endl;
    switch(worldsize) {
        case 1:
            this->initializeWorld(title, 6);
            break;
        case 2:
            this->initializeWorld(title, 8);
            break;
        case 3:
            this->initializeWorld(title, 12);
            break;
        default:
            std::cout << "[!] Byla zadana spatna velikost sveta, automaticky zvoleno 6x6" << std::endl;
            break;
    }
}
