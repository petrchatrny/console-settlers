#include <iostream>
#include <array>
#include <vector>

class Box {
private:
    double m_weight;
    std::string m_content;
    std::string m_owner;
public:
    Box(double weight, std::string content, std::string owner) {
        this->m_weight = weight;
        this->m_content = content;
        this->m_owner = owner;
    }

    std::string getContent() {
        return this->m_content;
    }

    std::string getOwner() {
        return this->m_owner;
    }
};

class Floor {
private:
    std::string m_label;
    std::array<Box*, 10> m_positions;
public:
    Floor(std::string label) {
        this->m_label = label;
        for(int i = 0; i < m_positions.size(); i++) {
            m_positions[i] = nullptr;
        }
    }

    void storeBox(Box* box, int index) {
        if(index >= 0 || index < m_positions.size()) {
            if(m_positions[index] == nullptr) m_positions[index] = box;
            else std::cout << "[Chyba] Tato pozice je obsazena" << std::endl;
        } else {
            std::cout << "[Chyba] Mimo rozsah" << std::endl;
        }
    }

    void removeBox(int index) {
        if(index >= 0 || index < m_positions.size()) {
            if(m_positions[index] != nullptr) m_positions[index] = nullptr;
            else std::cout << "[Chyba] Nulova hodnota" << std::endl;
        } else {
            std::cout << "[Chyba] Mimo rozsah" << std::endl;
        }
    }

    void printInfo() {
        std::cout << "[Floor Info] " << this->m_label << std::endl;
        for(int i = 0; i < m_positions.size(); i++) {
            std::cout << "[Poschodi " << i << "] " << m_positions[i]->getContent() << " / " << m_positions[i]->getOwner() << std::endl;
        }
    }
};

class Sklad {
private:
    std::vector<Floor*> m_floors;
public:
    Sklad(Floor* floor) {
        this->appendFloor(floor);
    }

    void appendFloor(Floor* floor) {
        this->m_floors.push_back(floor);
    }

    void destroyFloor() {
        this->m_floors.pop_back();
    }

    void ulozitDoSkladu(int floorIndex, int boxIndex, Box* box) {
        this->m_floors[floorIndex]->storeBox(box, boxIndex);
    }

    void odebratZeSkladu(int floorIndex, int boxIndex) {
        this->m_floors[floorIndex]->removeBox(boxIndex);
    }

    void printSklad() {
        std::cout << "[Sklad Info]" << std::endl;
        for(int i = 0; i < this->m_floors.size(); i++) {
            this->m_floors[i]->printInfo();
        }
    }
};

int main() {
    Floor* f = new Floor("Poschodi1");
    Box* b1 = new Box(37.5, "Drevo", "Alfred");
    Box* b2 = new Box(47.5, "Zelezo", "Alfred");
    f->removeBox(2);
    f->storeBox(b1, 0);
    f->storeBox(b2, 1);
    f->printInfo();

    Floor* f2 = new Floor("Poschodi2");
    Box* b3 = new Box(12.7, "Lentilky", "Alex");
    Sklad* sklad = new Sklad(f);
    sklad->appendFloor(f2);
    sklad->ulozitDoSkladu(1, 0, b3);
    sklad->printSklad();

    delete f;
    delete b1;
    delete b2;
    delete f2;
    delete sklad;
    delete b3;
    return 0;
}
