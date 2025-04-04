#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>
class WrongCat : public WrongAnimal
{

public:
    WrongCat(/* args */);
    virtual ~WrongCat();
    void makeSound();
    WrongCat(const WrongCat& other);
    WrongCat& operator = (const WrongCat& other);
};

#endif