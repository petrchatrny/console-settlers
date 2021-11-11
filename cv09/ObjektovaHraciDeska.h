//
// Created by tmsjk on 010, 10-11-21.
//

#ifndef ADVENTURA_OBJEKTOVAHRACIDESKA_H
#define ADVENTURA_OBJEKTOVAHRACIDESKA_H

#include <iostream>
#include <vector>
#include "HraciPole.h"

/**
 * @brief Trida reprezentuji hraci desku skladajici se z hernich poli, ktere jsou objekty
 *
 * Toto je nejdulezitejsi cast prikladu. Tato deska je schopna do sebe zapouzdrit zakladni
 * chovani hraci desky. Vas herni engine by mohl tuto desku vyuzivat. Vyresite tim skladovani
 * informaci o hernich polich a ziskate jiz nachystanou kostru pro polymorfni chovani.
 * Budete si moci odvodit ruzne dalsi vlastni potomky tridy HraciPole a udelat tak desku
 * plnou ruznych hernich "kamenu". Samozrejme si libovolne doplnujte funkcionalitu zejmena
 * do trody HerniPole, aby hra fungovala jak potrebujete.
 */
class ObjektovaHraciDeska {
private:
    /// Hraci deska, ktera obsahuje jednotliva herni pole
    std::vector<std::vector<HraciPole *> > m_deska;
    /// Pomocna promenna s poctem radku hraci desky
    int m_pocetRadek;
    /// Pomocna promenna s poctem sloupcu hraci desky
    int m_pocetSloupcu;

public:
    /// Konstruktor, ketry vytvori prazdne pole o predane velikosti
    ObjektovaHraciDeska(int pocetRadek, int pocetSloupcu);

    /// Pokud je to mozne, vrati objekt, ktery je na dane pozici v herni desce
    HraciPole *vrat(int radek, int sloupec);

    /// Vlozi novy objekt, ktery je potomkem tridy HraciPole na pozici v desce
    void vloz(int radek, int sloupec, HraciPole *pole);

    /// Vypise popisy jednotlivych hracich poli na obrazovku
    void vypisDesku();

    /**
     * @brief Metoda mazajici jednotliva herni pole
     *
     * Tato metoda je trochu zvlastni. Obvykle maze objekty ten, kdo je vytvari
     * Ale v tomto pripade by to bylo komplikovane, proto vznikla tato specialni
     * cistici metoda.
     */
    void vymazDesku();
};


#endif //ADVENTURA_OBJEKTOVAHRACIDESKA_H
