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




