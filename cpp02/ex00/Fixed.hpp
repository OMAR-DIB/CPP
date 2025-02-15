#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
 
class Fixed
{
private:
    int store;
    static const int fractionalBits = 8;

public:
    Fixed(/* args */);
    ~Fixed();
    Fixed(const Fixed& cp);
    Fixed& operator=(const Fixed& other);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};



#endif