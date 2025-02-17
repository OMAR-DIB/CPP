#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>

class Point {
private:
    const float x;
    const float y;

public:
    Point();
    Point(const float xVal, const float yVal);
    Point(const Point &other);
    Point &operator=(const Point &other);
    ~Point();

    float getX() const ;
    float getY() const ;
};
bool bsp(Point const a, Point const b, Point const c, Point const point);


#endif