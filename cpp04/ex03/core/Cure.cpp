#include "../includes/Cure.hpp"

Cure::Cure(/* args */): AMateria("cure")
{
    std::cout << "constructor of cure is initialized" << std::endl;
}

Cure::~Cure()
{
    std::cout << "destructor of cure is called" << std::endl;
}

AMateria* Cure::clone() const {
    return new Cure();
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
    std::cout << "Cure assignment operator called" << std::endl;
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    return *this;
}