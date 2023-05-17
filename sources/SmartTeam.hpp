#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP
#include "Character.hpp"
#include <vector>

namespace ariel
{

    class SmartTeam
    {
    private:
        std::vector<Character *> fighters;

    public:
        SmartTeam();
        void add(Character *fighter);
        void attack(SmartTeam *enemyTeam);
        int stillAlive() const;
        void print() const;
    };

#endif // SMARTTEAM_HPP
}