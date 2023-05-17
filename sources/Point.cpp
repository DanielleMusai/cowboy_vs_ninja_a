#include "Point.hpp"
#include <cmath>
#include <iostream>

namespace ariel {

    Point::Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    double Point::getX() const {
        return x;
    }

    double Point::getY() const {
        return y;
    }

    double Point::distance(const Point& point) const {
        double dx = x - point.x;
        double dy = y - point.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    void Point::print() const {
        std::cout << "(" << x << ", " << y << ")";
    }

    Point Point::moveTowards(const Point& source, const Point& destination, double distance) const {
        double dx = destination.x - source.x;
        double dy = destination.y - source.y;
        double currentDistance = std::sqrt(dx * dx + dy * dy);
        if (currentDistance <= distance) {
            return destination;
        }
        double ratio = distance / currentDistance;
        double newX = source.x + ratio * dx;
        double newY = source.y + ratio * dy;
        return Point(newX, newY);
    }

} // namespace ariel
