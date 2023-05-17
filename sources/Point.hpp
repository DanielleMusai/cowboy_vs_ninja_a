#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>

namespace ariel {

    class Point {
    private:
        double x;
        double y;

    public:
        Point(double xCoord, double yCoord);
        double getX() const;
        double getY() const;
        double distance(const Point& point) const;
        void print() const;
        Point moveTowards(const Point& source, const Point& destination, double distance) const;
    };

} // namespace ariel

#endif  // POINT_HPP
