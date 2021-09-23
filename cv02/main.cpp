#include <iostream>
#include <string>

class Balik {
public:
    std::string m_prijemce;
    std::string m_odesilatel;
    double m_vaha;
    int m_dobirka;

    Balik(std::string prijemce, std::string odesilatel, double vaha, int dobirka) {
        this->m_prijemce = prijemce;
        this->m_odesilatel = odesilatel;
        setVaha(vaha);
        this->m_dobirka = dobirka;
    }

    Balik(std::string prijemce, std::string odesilatel, double vaha) : Balik(prijemce, odesilatel, vaha, 0) {}
    Balik(std::string prijemce, std::string odesilatel) : Balik(prijemce, odesilatel, 0.0, 0) {}
    Balik(std::string prijemce, std::string odesilatel, int dobirka) : Balik(prijemce, odesilatel, 0.0, dobirka) {}

    void prohoditPrijemce() {
        std::string tempPrijemce = this->m_prijemce;
        this->m_prijemce = this->m_odesilatel;
        this->m_odesilatel = tempPrijemce;
    }

    void setVaha(double newVaha) {
        if(newVaha >= 0.0) this->m_vaha = newVaha;
        else this->m_vaha = 0.0;
    }

    void printInfo() {
        std::cout << "[Status] Odesílatel: " << this->m_odesilatel << ", příjemce: " << this->m_prijemce << "\n[Info] Váha: " << this->m_vaha << ", dobírka: " << this->m_dobirka << std::endl;
    }
};

int main() {
    Balik* b1 = new Balik("A", "B", 1.2, 5);
    b1->printInfo();
    b1->prohoditPrijemce();
    b1->printInfo();
    return 0;
}
