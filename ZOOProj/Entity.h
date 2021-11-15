#ifndef ZOOPROJ_ENTITY_H
#define ZOOPROJ_ENTITY_H


#include <string>

class Entity {
private:
    int m_coordX;
    int m_coordY;
    std::string m_appearance;

protected:
    Entity(int coordX, int coordY, std::string appearance);

public:
    int getCoordX();
    int getCoordY();
    std::string getAppearance();
};


#endif //ZOOPROJ_ENTITY_H
