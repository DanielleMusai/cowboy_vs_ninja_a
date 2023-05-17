#include "SmartTeam.hpp"
#include <iostream>

namespace ariel
{

    SmartTeam::SmartTeam() {}

    void SmartTeam::add(Character *fighter)
    {
        fighters.push_back(fighter);
    }

    void SmartTeam::attack(SmartTeam *enemyTeam) {}

    int SmartTeam::stillAlive() const
    {
        int aliveCount = 0;
        for (Character *fighter : fighters)
        {
            if (fighter->isAlive())
            {
                aliveCount++;
            }
        }
        return aliveCount;
    }

    void SmartTeam::print() const
    {
        for (Character *fighter : fighters)
        {
            fighter->print();
            std::cout << std::endl;
        }
    }
}