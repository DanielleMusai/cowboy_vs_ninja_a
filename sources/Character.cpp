#include "Character.hpp"

namespace ariel
{

    Character::Character(const std::string &name, const Point &location, int hitPoints)
        : name(name), location(location), hitPoints(hitPoints) {}

    Character::~Character() {}

    bool Character::isAlive() const
    {
        return false;
    }

    double Character::distance(const Character *other) const
    {
        return 0.0;
    }

    void Character::hit(int amount)
    {
        // Implementation left as an exercise
    }

    std::string Character::getName() const
    {
        return name;
    }

    Point Character::getLocation() const
    {
        return location;
    }
    std::string Character::print() const
    {
        return "Character: " + name;
    }
    Cowboy::Cowboy(const std::string &name, const Point &location)
        : Character(name, location, 110), bullets(6) {}

    Cowboy::~Cowboy() {}

    void Cowboy::shoot(Character *enemy)
    {
    }

    bool Cowboy::hasBullets() const
    {
        return true;
    }

    void Cowboy::reload()
    {
    }
    std::string Cowboy::print() const
    {
        return "Cowboy: " + getName();
    }

    Ninja::Ninja(const std::string &name, const Point &location, int speed)
        : Character(name, location, 100), speed(speed) {}

    Ninja::~Ninja() {}

    void Ninja::move(Character *enemy)
    {
    }

    void Ninja::slash(Character *enemy) {}

    std::string Ninja::print() const
    {

        return "Ninja: " + getName();
    }
    YoungNinja::YoungNinja(const std::string &name, const Point &location)
        : Ninja(name, location, 14) {}

    YoungNinja::~YoungNinja() {}

    std::string YoungNinja::print() const
    {

        return "Ninja: " + getName();
    }

    TrainedNinja::TrainedNinja(const std::string &name, const Point &location)
        : Ninja(name, location, 12) {}

    TrainedNinja::~TrainedNinja() {}

    std::string TrainedNinja::print() const
    {

        return "Ninja: " + getName();
    }

    OldNinja::OldNinja(const std::string &name, const Point &location)
        : Ninja(name, location, 8) {}

    OldNinja::~OldNinja() {}

    std::string OldNinja::print() const
    {

        return "Ninja: " + getName();
    }
} // namespace ariel
