#include "Point.hpp"
#include "geometry_utils.hpp"
#include <cmath>

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // Check if point is on edges or vertices
    if ((a.getX() == point.getX() && a.getY() == point.getY()) ||
        (b.getX() == point.getX() && b.getY() == point.getY()) ||
        (c.getX() == point.getX() && c.getY() == point.getY())) {
        return false;
    }

    // Convert Fixed values to float
    float ax = a.getX().toFloat();
    float ay = a.getY().toFloat();
    float bx = b.getX().toFloat();
    float by = b.getY().toFloat();
    float cx = c.getX().toFloat();
    float cy = c.getY().toFloat();
    float px = point.getX().toFloat();
    float py = point.getY().toFloat();

    // Calculate areas of triangles
    float area_abc = std::abs((ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)) / 2.0f);
    float area_abp = std::abs((ax * (py - by) + bx * (py - ay) + px * (ay - by)) / 2.0f);
    float area_bcp = std::abs((bx * (py - cy) + cx * (py - by) + px * (by - cy)) / 2.0f);
    float area_acp = std::abs((ax * (py - cy) + cx * (py - ay) + px * (ay - cy)) / 2.0f);

    // Check if point is inside the triangle
    return (area_abc >= area_abp + area_bcp + area_acp);
}
