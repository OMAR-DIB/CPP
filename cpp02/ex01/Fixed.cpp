#include "Fixed.hpp"

Fixed::Fixed(/* args */) : store(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int i_value)
{
    std::cout << "Int Constructor called" << std::endl;
    store = i_value << fractionalBits;
}

Fixed::Fixed(const float f_value)
{
    std::cout << "float Constructor called" << std::endl;
    store = roundf(f_value * (1 << fractionalBits));
}

Fixed &Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called" << std::endl;
    // Self-assignment check 
    if (this != &other){
        store = other.store;
    }

    return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return store;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	store = raw;
}

float Fixed::toFloat( void ) const{
    return static_cast<float>(store) / (1 << fractionalBits);
}

int Fixed::toInt( void ) const{
    return store >> fractionalBits;
}
std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}