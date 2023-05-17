#include "Character.hpp"

namespace ariel {

    Character::Character(const std::string& name, const Point& location)
        : name(name), location(location){}
  Character::Character(const Character& other)
        : name(other.name), location(other.location) {
    
    }

    bool Character::isAlive() const {
        return false;
    }

    double Character::distance(const Character* other) const {
        return 0.0;
    }

    void Character::hit(int amount) {
    }

    std::string Character::getName() const {
        return name;
    }

    Point Character::getLocation() const {
        return location;
    }

    std::string Character::print() const {
       return "Character: " + name;
    }

    // Implementation of Cowboy class
    Cowboy::Cowboy(const std::string& name, const Point& location)
        : Character(name, location) {}

    void Cowboy::shoot(Character* enemy) {}

    bool Cowboy::hasBullets() const {
        return true;
    }

    void Cowboy::reload() {}

    std::string Cowboy::print() const {
       return "Cowboy: " + getName() + ", Weapon: " + weapon;
    }

    // Implementation of Ninja class
    Ninja::Ninja(const std::string& name, const Point& location, int speed)
        : Character(name, location), speed(speed) {}

    void Ninja::move(Character* enemy) {}

    void Ninja::slash(Character* enemy) {}

    std::string Ninja::print() const {
       
       return "Ninja: " +getName() ;
    }

    // Implementation of YoungNinja class
    YoungNinja::YoungNinja(const std::string& name, const Point& location)
        : Ninja(name, location, 10) {}

    // Implementation of TrainedNinja class
    TrainedNinja::TrainedNinja(const std::string& name, const Point& location)
        : Ninja(name, location, 20) {}

    // Implementation of OldNinja class
    OldNinja::OldNinja(const std::string& name, const Point& location)
        : Ninja(name, location, 5) {}

} // namespace ariel


