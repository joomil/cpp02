#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point {
private:
    Fixed _x;
    Fixed _y;

public:
    Point(); // Default constructor
    Point(float const x, float const y); // Constructor with parameters
    Point(const Point&); // Copy constructor
    Point& operator=(const Point&); // Copy assignment operator
    ~Point(); // Destructor

    // Getter functions
    Fixed getX(void) const { return _x; }
    Fixed getY(void) const { return _y; }

    // Other useful functions...
};

#endif // POINT_HPP
