#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    virtual ~Cat();
    void makeSound();
    Cat(const Cat& other);
    Cat& operator = (const Cat& other);
};

#endif