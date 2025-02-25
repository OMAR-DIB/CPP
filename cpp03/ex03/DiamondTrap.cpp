#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") ,  ScavTrap(name), FragTrap(name)
{
	this->name = name;
	this->attackDamage = FragTrap::attackDamage;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	std::cout << "DiamondTrap " << this->name << " constructed" << std::endl;
}
DiamondTrap::DiamondTrap(DiamondTrap& other) : ClapTrap(other) ,  ScavTrap(other), FragTrap(other)
{
	*this= other;
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}
DiamondTrap& DiamondTrap::operator= (const DiamondTrap& other) 
{
    std::cout << "DiamondTrap Assignation operator called" << std::endl;
    if (this != &other) 
    {
        ClapTrap::operator=(other);
        this->name = other.name;
        this->attackDamage = other.attackDamage;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
    }
    return *this;
}


// Deconstructors
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Deconstructor for " << this->name << " called" << std::endl;
}
// Public Methods
void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Hello i am a DiamondTrap named " << this->name <<
	" and i am originated from the ClapTrap named " << ClapTrap::name << "." <<
	std::endl;
}