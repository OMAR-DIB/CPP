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
    Fixed& operator=(const Fixed& other){
        // Self-assignment check 
        if (this == &other){
            return *this;
        }
        store = other.store;

        return *this;
    }
};

Fixed::Fixed(/* args */) : store(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
}


#endif