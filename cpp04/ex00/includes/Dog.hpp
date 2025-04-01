#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
private:
    /* data */
public:
    Dog(/* args */);
    ~Dog();
    void makeSound();
    Dog(const Dog& other);
    Dog& operator = (const Dog& other);
};
#endif
