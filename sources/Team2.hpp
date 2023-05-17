#ifndef TEAM2_HPP
#define TEAM2_HPP
#include "Character.hpp"

namespace ariel
{
    class Team2
    {
    private:
        Character **fighters;
        int size;
        int capacity;

    public:
        Team2();
        void add(Character *fighter);
        void attack(Team2 *enemyTeam);
        int stillAlive() const;
        void print() const;
    };

#endif // TEAM2_HPP
}