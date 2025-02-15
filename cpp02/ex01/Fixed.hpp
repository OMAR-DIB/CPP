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
    Fixed(const Fixed& cp);
    Fixed(const int i_value);
    Fixed(const float f_value);
    Fixed& operator=(const Fixed& other);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
    friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);
};



#endif