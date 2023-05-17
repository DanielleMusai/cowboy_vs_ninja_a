#ifndef TEAM_HPP
#define TEAM_HPP
#include "Character.hpp"

namespace ariel
{
    class Team
    {
    private:
        Character *leader;
        Character **fighters;
        int size;
        int capacity;

    public:
        Team();
        Team(Character *teamLeader);
        void add(Character *fighter);
        void attack(Team *enemyTeam);
        int stillAlive() const;
        void print() const;
    };
}

#endif // TEAM_HPP
