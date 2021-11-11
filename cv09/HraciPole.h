//
// Created by tmsjk on 010, 10-11-21.
//

#ifndef ADVENTURA_HRACIPOLE_H
#define ADVENTURA_HRACIPOLE_H

#include <iostream>

/**
   * @brief Abstraktni trida predstavujici obecne herni pole
   *
   * Tato trida predstavuje obecne hraci pole. Toto pole se pouziva pouze pro
   * dedeni ruznych konkretnich typu hracich poli. Slouzi hlavne k tomu, abychom
   * mohli mit univerzalni ukazatel na libovolne hraci pole, dosadili si za nej
   * co uzname za vhodne a pak provolavali ruzne implementace metod (polym.).
   * Vytvarejte si vlastni potomky a doplnujte atributy a metody podle potreby.
   */
class HraciPole {
    /// Testovaci atribut, ktery se dedi do vsech potomku
    std::string m_popis;

public:
    HraciPole(std::string popis);

    /// Testovaci metoda, ktera se dedi do vsech potomku
    std::string getPopis();

    /// Tridy, ktere budou mit potomky by mely mit virt. dest., pak se zavola vzdy destruktor spravneho potomka
    virtual ~HraciPole() {};
};


#endif //ADVENTURA_HRACIPOLE_H
