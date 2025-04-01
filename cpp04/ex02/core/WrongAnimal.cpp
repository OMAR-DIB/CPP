#include "../includes/WrongAnimal.hpp"


WrongAnimal::WrongAnimal(): type("ANIMAL") 
{
    std::cout << "constructor wrong Animal initialized" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "destructor wrong Animal called" << std::endl;
}
void WrongAnimal::makeSound(){
    std::cout << " wrong Animal sound" << std::endl;
}


WrongAnimal::WrongAnimal(const WrongAnimal& other){
    *this = other;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}