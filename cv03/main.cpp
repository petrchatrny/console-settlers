#include <iostream>
#include <string>

class Developer {
private:
    static int s_developersCount;
    std::string m_jmeno;
    int m_hodinovaMzda;
    double m_odpracovaneHodiny;
    int m_bonusPrescas;
    int m_pocetChyb;
    int m_srazka;
public:
    Developer(std::string jmeno) : Developer(jmeno, 280, 60, 30) {};
    Developer(std::string jmeno, int mzda, int bonus, int srazka) {
        this->m_jmeno = jmeno;
        this->m_hodinovaMzda = mzda;
        this->m_bonusPrescas = bonus;
        this->m_pocetChyb = 0;
        this->m_srazka = srazka;
        s_developersCount++;
    }

    ~Developer() {
        s_developersCount--;
        std::cout << "[Developer] " << this->m_jmeno << " smazán." << std::endl;
    }

    void pracuj(double pocetHodiny) {
        this->m_odpracovaneHodiny += pocetHodiny;
    }

    void konecMesice() {
        this->m_odpracovaneHodiny = 0;
        this->m_pocetChyb;
    }

    double getMzda() {
        double zakladMzda = (this->m_odpracovaneHodiny*this->m_hodinovaMzda) - (this->m_pocetChyb*this->m_srazka);
        return (this->m_odpracovaneHodiny >= 40 ? (zakladMzda + (this->m_odpracovaneHodiny*this->m_bonusPrescas)) : zakladMzda);
    }

    void printInfo() {
        std::cout << "[Developer] " << this->m_jmeno <<
                  " odpracoval " << this->m_odpracovaneHodiny <<
                  " hodin, jeho mzda činí " << this->getMzda() <<
                  " (hodinová mzda: " << this->m_hodinovaMzda << ", bonus za přesčas: " << this->m_bonusPrescas << ", srážka za chybu: " << this->m_srazka << ", počet chyb: " << this->m_pocetChyb << ")" <<
                  std::endl;
    }

    void evidujChybu() {
        this->m_pocetChyb++;
    }

    static int getDevelopersCount() {
        return s_developersCount;
    }
};
int Developer::s_developersCount = 0;
int main() {
    std::cout << "Developers Count: " << Developer::getDevelopersCount() << std::endl;
    Developer* d1 = new Developer("Karel");
    Developer* d2 = new Developer("Ivan", 345, 10, 80);
    d1->pracuj(168);
    d1->evidujChybu();
    d2->pracuj(28);
    d2->pracuj(11);
    d1->printInfo();
    d2->printInfo();
    d1->konecMesice();
    d2->konecMesice();
    d1->printInfo();
    std::cout << "Developers Count: " << Developer::getDevelopersCount() << std::endl;
    delete d1;
    delete d2;
    std::cout << "Developers Count: " << Developer::getDevelopersCount() << std::endl;
    return 0;
}