//
// Created by tmsjk on 010, 10-11-21.
//

#include "HraciPole.h"

HraciPole::HraciPole(std::string popis){
    if (popis == ""){
        std::cerr << "HraciPole::HraciPole - snazite se do popisu pole nastavit prazdnou hodnotu" << std::endl;
    }
    m_popis = popis;
}


std::string HraciPole::getPopis(){
    return m_popis;
}