//
// Created by xweiss3 on 11.11.2021.
//

#include "Planeta.h"

Planeta::Planeta(std::string popis, int dostupneMnozstviRudy) : HraciPole(popis) {
    this->m_ulozeneMnozstviRudy = dostupneMnozstviRudy;
}

int Planeta::vytezitDavkuRudy() {
    int davka = this->m_ulozeneMnozstviRudy/20;
    this->m_ulozeneMnozstviRudy -= davka;
    return davka;
}