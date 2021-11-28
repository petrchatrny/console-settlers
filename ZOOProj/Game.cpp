
#include <iostream>
#include "Game.h"

Game* Game::s_instance = nullptr;

Game::Game() {
    m_gameOver = false;
    m_activeBuilding = nullptr;
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

void Game::printInfoMessage(std::string message) {
    std::cout << "[i] " << message << std::endl;
}

void Game::printInputMessage(std::string message) {
    if (m_world == nullptr) {
        std::cout << ":> " << message << std::endl;
    } else if (m_activeBuilding == nullptr) {
        std::cout << ":>" << m_world->getName() << "> " << message << std::endl;
    } else {
        std::cout << ":>" << m_world->getName() << ">" << m_activeBuilding->getName() << "> " << message
                  << std::endl;
    }
}

void Game::printErrorMessage(std::string message) {
    std::cout << "[!] " << message << std::endl;
}

void Game::start() {
    std::string title;
    int worldSize;

    std::cout << "*** Welcome to the game Console Settler ***" << std::endl;

    printInputMessage("Enter world's name: ");
    std::cin >> title;

    printInputMessage("Pick the size of the world -  6x6 (1); 8x8 (2); 12x12 (3): ");
    std::cin >> worldSize;

    switch (worldSize) {
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
            printErrorMessage("The wrong size of the world was entered, game chose 6x6");
            initializeWorld(title, 6);
            break;
    }
    commandCycle();
}

void Game::end(GameResult result) {
    m_gameOver = true;
    std::cout << "*** Game over ***" << std::endl;
    switch (result) {
        case GameResult::WIN:
            std::cout << "*** Congratulations, you won! ***" << std::endl;
            break;
        case GameResult::LOSE:
            std::cout << "*** Pity, you lost, better luck next time! ***" << std::endl;
            break;
    }

    std::cout << "*** Thank you for playing our game! ***" << std::endl;
    std::cout << "Authors: Petr Chatrný, Martin Weiss, Daniil Astapenko" << std::endl;
}

void Game::commandCycle() {
    int commandNumber;
    while (!m_gameOver) {
        std::cout << std::endl;
        printInputMessage("Enter command number, for printing help enter 0: ");
        std::cin >> commandNumber;
        executeCommand(commandNumber);
    }
}

void Game::executeCommand(int command) {
    if (m_activeBuilding == nullptr) {
        switch (command) {
            case 0:
                printHelp();
                break;
            case 1:
                m_world->getMap()->printMap();
                break;
            case 2:
                enterTheBuilding();
                break;
                // EasterEgg, don't include this to the list of available commands in printHelp()
            case 66:
                std::cout << "*** RIP JEDI KNIGHTS ***" << std::endl;
                break;
            case 99:
                end(GameResult::LOSE);
                break;
            default:
                break;
        }
    } else {
        m_activeBuilding->executeCommand(command);
    }
}

void Game::enterTheBuilding() {
    buildings::Coords coords = buildings::Coords{};

    printInputMessage("Enter coords (x y) of building you want to proceed: ");
    std::cin >> coords.x >> coords.y;

    m_activeBuilding = m_world->getMap()->getBuilding(coords);
    if (m_activeBuilding == nullptr) {
        printErrorMessage("Couldn't proceed building at this coords");
    } else {
        printInfoMessage("Building successfully proceeded");
    }
}

void Game::quitTheBuilding() {
    m_activeBuilding = nullptr;
}

void Game::printHelp() {
    // TODO Daniil
}
