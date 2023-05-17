#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <string>

namespace ariel {

    class Character {
    private:
    std::string name;
        Point location;
        int hitPoints;

    public:
       

        Character(const std::string& name, const Point& location);
        Character(const Character& other);
        bool isAlive() const;
        double distance(const Character* other) const;
        void hit(int amount);
        std::string getName() const;
        Point getLocation() const;
        virtual std::string print() const;
    };

    class Cowboy : public Character {
    private:
        std::string weapon;
        int ballsAmo;

    public:
        Cowboy(const std::string& name, const Point& location);
        void shoot(Character* enemy);
        bool hasBullets() const;
        void reload();
        std::string print() const override;
    };

    class Ninja : public Character {
    private:
        int speed;

    public:
        Ninja(const std::string& name, const Point& location, int speed);
        void move(Character* enemy);
        void slash(Character* enemy);
        std::string print() const override;
    };

    class YoungNinja : public Ninja {
    public:
        YoungNinja(const std::string& name, const Point& location);
  
    };

    class TrainedNinja : public Ninja {
    public:
        TrainedNinja(const std::string& name, const Point& location);
     
    };

    class OldNinja : public Ninja {
    public:
        OldNinja(const std::string& name, const Point& location);
     
    };

} // namespace ariel

#endif // CHARACTER_HPP
