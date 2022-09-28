
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

void Game::printMessage(std::string message, MessageType type) {
    switch (type) {
        case INFO:
            std::cout << std::endl << "[i] " << message << std::endl;
            break;
        case INPUT:
            if (m_world == nullptr) {
                std::cout << ":> " << message;
            } else if (m_activeBuilding == nullptr) {
                std::cout << ":>" << m_world->getName() << "> " << message;
            } else {
                std::cout << ":>" << m_world->getName() << ">" << m_activeBuilding->getName() << "> " << message;
            }
            break;
        case ERROR:
            std::cout << std::endl << "[!] " << message << std::endl;
            break;
    }
}

void Game::start() {
    std::string title;
    int worldSize;

    std::cout << "*** Welcome to the game Console Settler ***" << std::endl;

    printMessage("Enter world's name: ", INPUT);
    std::cin >> title;

    printMessage("Pick the size of the world -  6x6 (1); 8x8 (2); 12x12 (3): ", INPUT);
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
            printMessage("The wrong size of the world was entered, game chose 6x6", ERROR);
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

int Game::processInput(std::string input) {
    bool isCorrect = true;
    int result = 0;
    int i = 0;
    while (i < input.size()) {
        if (!std::isdigit(input.at(i))) {
            isCorrect = false;
        } else {
            result *= 10;
            result += input.at(i) - '0';
        }
        i++;
    }
    if (isCorrect) {
        return result;
    }
    return -1;
}

void Game::commandCycle() {
    std::string input;
    while (!m_gameOver) {
        std::cout << std::endl;
        printMessage("Enter command number (0 for help): ", INPUT);
        std::cin >> input;

        int command = processInput(input);
        if (command < 0) {
            printMessage("Wrong input", ERROR);
        } else {
            executeCommand(command);
        }
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
                printMessage("Unknown command", ERROR);
                break;
        }
    } else {
        m_activeBuilding->executeCommand(command);
    }
}

void Game::enterTheBuilding() {
    buildings::Coords coords = buildings::Coords{};

    printMessage("Enter coords (x y) of building you want to enter: ", INPUT);
    std::cin >> coords.x >> coords.y;

    m_activeBuilding = m_world->getMap()->getBuilding(coords);
    if (m_activeBuilding == nullptr) {
        printMessage("Couldn't enter building at this coords", ERROR);
    } else {
        printMessage("Building successfully entered", INFO);
    }
}

void Game::quitTheBuilding() {
    m_activeBuilding = nullptr;
}

void Game::printHelp() {
    std::cout << "----- HELP OF THE GAME -----" << std::endl;
    std::cout << "[0] - help" << std::endl;
    std::cout << "[1] - will print map" << std::endl;
    std::cout << "[2] - will enter the building" << std::endl;
    std::cout << "[99] - will end the game by surrender" << std::endl;
    std::cout << "----------------------------" << std::endl;
}
