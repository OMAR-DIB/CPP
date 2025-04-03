#include "../includes/AMateria.hpp"

AMateria::AMateria(std::string const & type) {
    std::cout << "Type constructor of AMaterial is initialized" << std::endl;
	this->type = type;
}

AMateria::~AMateria() {
    std::cout << "destructor of AMaterial is called" << std::endl;
}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "* uses " << type << " on " << target.getName() << " *" << std::endl;
}


AMateria::AMateria(const AMateria& other) : type(other.type)
{
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    std::cout << "AMateria assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}