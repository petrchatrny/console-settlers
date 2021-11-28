
#include <iostream>
#include "Game.h"

Game* Game::s_instance = nullptr;

Game::Game() {
    m_gameOver = false;
    m_gameResult = GameResult::NONE;
    m_proceededBuilding = nullptr;
    m_world = nullptr;
}

Game::~Game() {
    delete Game::m_world;
    delete Game::s_instance;
}

Game* Game::getInstance() {
    if (s_instance == nullptr) {
        s_instance = new Game();
    }
    return s_instance;
}

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

Game *Game::getInstance() {
    return Game::s_instance;
}

void Game::proceedToBuilding(buildings::Coords coords) {
    this->m_proceededBuilding = this->s_instance->getWorld()->getMap()->getBuilding(coords);
}
