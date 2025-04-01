#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal(/* args */);
    Animal(const std::string &type);
    virtual ~Animal();
    Animal(const Animal& other);
    std::string getType();
    Animal& operator = (const Animal& other);
    virtual void makeSound() = 0;// virtual without init
};


#endif