//
// Created by xweiss3 on 11.11.2021.
//

#ifndef CV09_PLANETA_H
#define CV09_PLANETA_H

#include "HraciPole.h"

class Planeta : public HraciPole {
private:
    int m_ulozeneMnozstviRudy;
public:
    Planeta(std::string popis, int dostupneMnozstviRudy);
    int vytezitDavkuRudy();
};


#endif //CV09_PLANETA_H
