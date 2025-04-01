#include "../includes/Cat.hpp"

Cat::Cat(/* args */) : Animal("Cat")
{
    std::cout << "constructor initialized of "<< this->type << std::endl;
}

Cat::~Cat()
{
    std::cout << "destructor called "  << this->type<< std::endl;
}

void Cat::makeSound(){
    std::cout << "* meow! *" << std::endl;
}

Cat::Cat(const Cat& other): Animal() {
    *this = other;
}

Cat& Cat::operator = (const Cat& other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}