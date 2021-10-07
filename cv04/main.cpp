#include <iostream>
#include <string>

class Drak{
private:
    float m_sila;
    float m_zdravi;
    float m_obrana;

    void setObrana(float obrana) {
        if(obrana < 0 || obrana > 200) {
            /* logger */

        } else {
            this->m_obrana = obrana;
        }
    }
public:
    Drak(float sila, float obrana) {
        this->m_zdravi = 100;
        this->m_sila = sila;
        this->setObrana(obrana);
    }

    float getSila() {
        return this->m_sila;
    }

    float getZdravi() {
        return this->m_zdravi;
    }

    float getObrana() {
        return this->m_obrana;
    }

    void ubratZdravi(float zdravi) {
        this->m_zdravi -= zdravi;
        if(this->m_zdravi < 0.1) {
            std::cout << "Drak zemřel" << std::endl;
        }
    }
};

class Rytir{
private:
    float m_sila;
    float m_zdravi;
    float m_obrana;
    std::string m_name;

    void setObrana(float obrana) {
        if(obrana < 0 || obrana > 200) {
            std::cout << "Špatná hodnota obrany" << std::endl;
        } else {
            this->m_obrana = obrana;
        }
    }
public:
    Rytir(float sila, float obrana, std::string jmeno) {
        this->m_zdravi = 100;
        this->m_sila = sila;
        this->m_name = jmeno;
        this->setObrana(obrana);
    }

    float getSila() {
        return this->m_sila;
    }

    float getZdravi() {
        return this->m_zdravi;
    }

    float getObrana() {
        return this->m_obrana;
    }

    std::string getName() {
        return this->m_name;
    }

    void ubratZdravi(float zdravi) {
        this->m_zdravi -= zdravi;
        if(this->m_zdravi < 0.1) {
            std::cout << "Rytíř zemřel" << std::endl;
        }
    }

    void attack(Drak *drak) {
        float drakSila = drak->getSila();
        float drakObrana = drak->getObrana();
        if(this->m_sila > drakObrana) {
            std::cout << "Vyhrál rytíř" << std::endl;
            drak->ubratZdravi(this->m_sila-drakObrana);
        } else if(drakSila > this->m_obrana) {
            std::cout << "Vyhrál drak" << std::endl;
            this->ubratZdravi(drakSila-this->m_obrana);
        }
    }
};
/*
class Logger{
private:
    Logger m_log;
    std::string m_chyby;
    Logger() {

    }
public:
    Logger getLogger() {
        return this->m_log;
    }

    void pridatChybu(std::string popis) {

    }

    std::string getChyby() {
        return this->m_chyby;
    }
};
*/
int main() {
    Drak* drak = new Drak(50, 40);
    Rytir* rytir = new Rytir(60, 45, "F");
    rytir->attack(drak);
    std::cout << "Zdraví rytíře: " << rytir->getZdravi() << std::endl;
    std::cout << "Zdraví draka: " << drak->getZdravi() << std::endl;
    delete drak;
    delete rytir;
    return 0;
}
