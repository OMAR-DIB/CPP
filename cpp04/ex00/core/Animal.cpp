#include "../includes/Animal.hpp"

Animal::Animal(/* args */)
{
    std::cout << "constructor Animal initialized" << std::endl;
}

Animal::Animal(const std::string& type)
{
	std::cout << "Type constructor of Animal" << std::endl;
	this->type = type;
}

Animal::~Animal()
{
    std::cout << "destructor Animal called" << std::endl;
}

std::string Animal::getType(){
    return type;
}
void Animal::makeSound(){
    std::cout << "* Animal sound" << std::endl;
}

Animal::Animal(const Animal& other){
    *this = other;
}

Animal& Animal::operator = (const Animal& other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}