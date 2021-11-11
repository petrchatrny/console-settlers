//
// Created by xweiss3 on 11.11.2021.
//

#include "GameEngine.h"
#include "Planeta.h"
GameEngine::GameEngine() {
    this->m_hraciDeska = new ObjektovaHraciDeska(3, 3);
    this->inicializujBunky();
}

void GameEngine::inicializujBunky() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            this->m_hraciDeska->vloz(i, j, new Planeta("Saturn", 40*i*j));
        }
    }
}

void GameEngine::vypisNapovedu() {
    std::cout << "-----------------" << std::endl;
    std::cout << "[0] Konec hry" << std::endl;
    std::cout << "[1] Nápovědu" << std::endl;
    std::cout << "[2] Výpis hrací desky" << std::endl;
    std::cout << "-----------------" << std::endl;
}

void GameEngine::hraj() {
    int rozhodnuti = 30;
    do {
        std::cout << "Vyber akci([0] exit, [1] nápověda): ";
        std::cin >> rozhodnuti;

        switch (rozhodnuti) {
            case 1:
                this->vypisNapovedu();
                break;
            case 2:
                this->m_hraciDeska->vypisDesku();
                break;
            default:
                break;
        }
    } while (rozhodnuti != 0);
}

GameEngine::~GameEngine() {
    this->m_hraciDeska->vymazDesku();
    delete this->m_hraciDeska;
}