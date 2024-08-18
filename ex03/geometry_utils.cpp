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

    // Calculate areas of triangles
    float area_abc = abs((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2.0f);
    float area_abp = abs((a.getX() * (point.getY() - b.getY()) + b.getX() * (point.getY() - a.getY()) + point.getX() * (a.getY() - b.getY())) / 2.0f);
    float area_bcp = abs((b.getX() * (point.getY() - c.getY()) + c.getX() * (point.getY() - b.getY()) + point.getX() * (b.getY() - c.getY())) / 2.0f);
    float area_acp = abs((a.getX() * (point.getY() - c.getY()) + c.getX() * (point.getY() - a.getY()) + point.getX() * (a.getY() - c.getY())) / 2.0f);

    // Check if point is inside the triangle
    return (area_abc >= area_abp + area_bcp + area_acp);
}
