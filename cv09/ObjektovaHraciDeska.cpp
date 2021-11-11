//
// Created by tmsjk on 010, 10-11-21.
//

#include "ObjektovaHraciDeska.h"


ObjektovaHraciDeska::ObjektovaHraciDeska(int pocetRadek, int pocetSloupcu) {
    std::vector<HraciPole *> pomocnyRadek(pocetSloupcu, nullptr);

    // lze samozrejme i jinak
    m_deska.resize(pocetRadek);
    for (int i = 0; i < pocetRadek; i++) {
        m_deska[i] = pomocnyRadek;
    }
    m_pocetSloupcu = pocetSloupcu;
    m_pocetRadek = pocetRadek;
}

HraciPole *ObjektovaHraciDeska::vrat(int radek, int sloupec) {
    // kontroluji, zda nepristupujeme mimo rozsah pole
    if ((radek < m_pocetRadek) and (sloupec < m_pocetSloupcu)) {
        // kontroluji, zda je na pozici objekt
        if (m_deska[radek][sloupec] != nullptr) {
            return m_deska[radek][sloupec];
        } else {
            std::cerr << "ObjektovaHraciDeska::vrat - Pokus o pristup do pole bez objektu" << std::endl;
            std::cerr << "Pozadadovana pozice [" << radek << ", " << sloupec << "]." << std::endl;
            return nullptr;
        }
    } else {
        std::cerr << "ObjektovaHraciDeska::vrat - Pokus o pristup mimo rozsah desky!" << std::endl;
        std::cerr << "Pozadadovana pozice [" << radek << ", " << sloupec << "]." << std::endl;
        std::cerr << "Maximalni pozice [" << m_pocetRadek - 1 << ", " << m_pocetSloupcu - 1 << "]." << std::endl;
        return nullptr;
    }
}

void ObjektovaHraciDeska::vloz(int radek, int sloupec, HraciPole *pole) {
    // kontrola, zda nepristupuji mimo rozsah pole
    if((radek < m_pocetRadek) and (sloupec < m_pocetSloupcu)) {
        this->m_deska[radek][sloupec] = pole;
    } else {
        std::cerr << "ObjektovaHraciDeska::vloz - Pokus o pristup mimo rozsah desky!" << std::endl;
        std::cerr << "Pozadadovana pozice [" << radek << ", " << sloupec << "]." << std::endl;
        std::cerr << "Maximalni pozice [" << m_pocetRadek - 1 << ", " << m_pocetSloupcu - 1 << "]." << std::endl;
    }
}

void ObjektovaHraciDeska::vypisDesku() {
    for(int i = 0; i < this->m_pocetRadek; i++) {
        std::cout << "|\t";
        for(int j = 0; j < this->m_pocetSloupcu; j++) {
            std::cout << this->m_deska[i][j]->getPopis() << "\t|\t";
        }
        std::cout << std::endl;
    }
}

void ObjektovaHraciDeska::vymazDesku() {
    for(int i = 0; i < this->m_pocetRadek; i++) {
        for(int j = 0; j < this->m_pocetSloupcu; j++) {
            if(this->m_deska[i][j] != nullptr) delete this->m_deska[i][j];
            this->m_deska[i][j] = nullptr;
        }
    }
}
