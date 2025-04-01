#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:
    /* data */
public:
    Cat(/* args */);
    ~Cat();
    void makeSound();
    Cat(const Cat& other);
    Cat& operator = (const Cat& other);
};

#endif