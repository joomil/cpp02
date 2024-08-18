#include "Point.hpp"
#include "geometry_utils.hpp"
#include <iostream>

int main() {
    Point a(-10, -10);
    Point b(10, -10);
    Point c(10, 10);
    Point point(0, 0);

    bool result = bsp(a, b, c, point);
    std::cout << "Is point inside the triangle? " << (result ? "Yes" : "No") << std::endl;

    return 0;
}
