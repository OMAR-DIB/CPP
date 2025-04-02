#include "../includes/Ice.hpp"

Ice::Ice() : AMateria("ice") {
    std::cout << "constructor of Ice is initialized" << std::endl;
}   

Ice::~Ice(){
    std::cout << "destructor of Ice is called" << std::endl;
}


AMateria* Ice::clone() const {
    return new Ice();
}

void Ice::use(ICharacter& target){
    
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
