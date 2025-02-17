#include "Point.hpp"

// Constructor that initializes x and y to 0
Point::Point() : x(0), y(0) {}

// Constructor that initializes x and y with given values
Point::Point(const float xVal, const float yVal) : x(xVal), y(yVal) {}

// Copy constructor
Point::Point(const Point &other) : x(other.x), y(other.y) {}

// Copy assignment operator overload
Point &Point::operator=(const Point &other) {
    if (this != &other) {
        // x and y are const, so we cannot reassign them
        // This is just for Orthodox Canonical Form compliance
        return *this;
    }
    return *this;
}

// Destructor
Point::~Point() {}

float Point::getX() const 
{ 
    return x; 
}

float Point::getY() const 
{
    return y;
}

// Helper function to compute area using the determinant method
static float area(Point const &p1, Point const &p2, Point const &p3) {
    return std::abs((p1.getX() * (p2.getY() - p3.getY()) + p2.getX() * (p3.getY() - p1.getY()) + p3.getX() * (p1.getY() - p2.getY())) / 2.0);
}

// bsp function to check if the point is inside the triangle
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    float A = area(a, b, c);    // Area of the whole triangle
    float A1 = area(point, b, c); // Area of subtriangle PBC
    float A2 = area(a, point, c); // Area of subtriangle APC
    float A3 = area(a, b, point); // Area of subtriangle ABP

    // Check if sum of sub-areas equals total area
    return (A == (A1 + A2 + A3) && A1 > 0 && A2 > 0 && A3 > 0);
}
