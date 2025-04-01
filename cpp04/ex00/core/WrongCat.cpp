#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongAnimal of type " << type << " created." << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destroyed." << std::endl;
}

void WrongCat::makeSound() {
    std::cout << "Wrong cat Barking!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal() {
    *this = other;
}

WrongCat& WrongCat::operator = (const WrongCat& other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}