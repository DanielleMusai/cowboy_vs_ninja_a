#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Point.hpp"
#include <string>
namespace ariel
{

    class Character
    {
    public:
        Character(const std::string &name, const Point &location, int hitPoints);
        virtual ~Character();

        bool isAlive() const;
        double distance(const Character *other) const;
        void hit(int amount);
        std::string getName() const;
        Point getLocation() const;
        virtual std::string print() const;

    protected:
        std::string name;
        int hitPoints;
        Point location;
    };

    class Cowboy : public Character
    {
    public:
        Cowboy(const std::string &name, const Point &location);
        virtual ~Cowboy();

        void shoot(Character *enemy);
        bool hasBullets() const;
        void reload();
        std::string print() const override;

    private:
        int bullets;
    };

    class Ninja : public Character
    {
    public:
        Ninja(const std::string &name, const Point &location, int speed);
        virtual ~Ninja();

        void move(Character *enemy);
        void slash(Character *enemy);
        std::string print() const override;

    private:
        int speed;
    };

    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(const std::string &name, const Point &location);
        virtual ~YoungNinja();
        std::string print() const override;
    };

    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(const std::string &name, const Point &location);
        virtual ~TrainedNinja();
        std::string print() const override;
    };

    class OldNinja : public Ninja
    {
    public:
        OldNinja(const std::string &name, const Point &location);
        virtual ~OldNinja();
        std::string print() const override;
    };
}

#endif // CHARACTER_HPP
