#include "Fixed.hpp"

Fixed::Fixed(/* args */) : store(0)
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed::Fixed(const int i_value)
{
    store = i_value << fractionalBits;
}

Fixed::Fixed(const float f_value)
{
    store = roundf(f_value * (1 << fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &other)
{
    // Self-assignment check
    if (this != &other)
    {
        store = other.store;
    }

    return *this;
}

int Fixed::getRawBits(void) const
{
    return store;
}

void Fixed::setRawBits(int const raw)
{
    store = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(store) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
    return store >> fractionalBits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
    os << obj.toFloat();
    return os;
}

Fixed Fixed::operator-(const Fixed &other)
{
    Fixed res = store - other.store;
    return res;
}

Fixed Fixed::operator+(const Fixed &other)
{
    Fixed res = store + other.store;
    return res;
}

Fixed Fixed::operator*(const Fixed &other)
{
    Fixed result;
    result.setRawBits((u_int64_t(store) * u_int64_t(other.getRawBits())) / (1 << fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed &other)
{
    Fixed result;
    result.setRawBits((u_int64_t(store) * (1 << fractionalBits)) / other.getRawBits());
    return result;
}

bool Fixed::operator<(const Fixed &other) const
{
    return store < other.store;
}

bool Fixed::operator>(const Fixed &other) const
{
    return store > other.store;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return store <= other.store;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return store >= other.store;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return store != other.store;
}

bool Fixed::operator==(const Fixed &other) const
{
    return store == other.store;
}

Fixed Fixed::operator++(void)
{
    store += 1;
    return *this;
}

Fixed Fixed::operator--(void)
{
    store -= 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    store += 1;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    store -= 1;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
    return (a > b) ? a : b;
}