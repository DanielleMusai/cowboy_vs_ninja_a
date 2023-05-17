#include "Team.hpp"
#include <iostream>

using namespace std;
namespace ariel
{

    Team::Team(){};
    Team::Team(Character *teamLeader) : leader(teamLeader), size(0), capacity(10)
    {
        fighters = new Character *[static_cast<size_t>(capacity)];
    }

    void Team::add(Character *fighter)
    {
        if (size < capacity)
        {
            fighters[size] = fighter;
            size++;
        }
    }

    void Team::attack(Team *enemyTeam) {}

    int Team::stillAlive() const
    {
        int aliveCount = 0;
        for (int i = 0; i < size; i++)
        {
            if (fighters[i]->isAlive())
            {
                aliveCount++;
            }
        }
        return aliveCount;
    }

    void Team::print() const
    {
        for (int i = 0; i < size; i++)
        {
            fighters[i]->print();
            std::cout << std::endl;
        }
    }
}