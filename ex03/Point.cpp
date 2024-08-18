#include "Point.hpp"

// Default constructor
Point::Point() : _x(0), _y(0) {}

// Constructor with parameters
Point::Point(float const x, float const y) : _x(x), _y(y) {}

// Copy constructor
Point::Point(const Point& p) : _x(p._x), _y(p._y) {}

// Copy assignment operator
Point& Point::operator=(const Point& p) {
    if (this != &p) {
        _x = p._x; // Ensure this is safe if _x is const
        _y = p._y; // Ensure this is safe if _y is const
    }
    return *this;
}

// Destructor
Point::~Point() {}
