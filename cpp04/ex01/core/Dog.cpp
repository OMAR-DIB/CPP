#include "../includes/Dog.hpp"


Dog::Dog(/* args */) : Animal("Dog")
{
    std::cout << "constructor initialized of "<< this->type << std::endl;
    brain = new Brain();
}

Dog::~Dog()
{
    std::cout << "destructor called "  << this->type<< std::endl;
    delete brain;
}

void Dog::makeSound(){
    std::cout << "* Barking! *" << std::endl;
}

Dog::Dog(const Dog& other): Animal() {
    *this = other;
}

Dog& Dog::operator = (const Dog& other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}