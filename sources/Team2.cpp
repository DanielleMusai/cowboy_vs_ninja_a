#include "Team2.hpp"
#include <iostream>

using namespace std;

namespace ariel {


Team2::Team2() : size(0), capacity(10) {
    fighters = new Character*[static_cast<size_t>(capacity)];

}

void Team2::add(Character* fighter) {
    if (size < capacity) {
        fighters[size] = fighter;
        size++;
    }
}

void Team2::attack(Team2* enemyTeam) {}

int Team2::stillAlive() const {
    int aliveCount = 0;
    for (int i = 0; i < size; i++) {
        if (fighters[i]->isAlive()) {
            aliveCount++;
        }
    }
    return aliveCount;
}

void Team2::print() const {
    for (int i = 0; i < size; i++) {
        fighters[i]->print();
        std::cout << std::endl;
    }
}
}