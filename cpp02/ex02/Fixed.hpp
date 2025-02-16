#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
class Fixed
{
private:
    int store;
    static const int fractionalBits = 8;

public:
    Fixed(/* args */);
    ~Fixed();
    Fixed(const Fixed &cp);
    Fixed(const int i_value);
    Fixed(const float f_value);
    Fixed &operator=(const Fixed &other);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    friend std::ostream &operator<<(std::ostream &os, const Fixed &obj);

    Fixed operator-(const Fixed &other);
    Fixed operator+(const Fixed &other);
    Fixed operator*(const Fixed &other);
    Fixed operator/(const Fixed &other);

    bool operator<(const Fixed &other) const;
    bool operator>(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;

    Fixed operator++(void);
    Fixed operator--(void);
    Fixed operator++(int);
    Fixed operator--(int);

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

#endif