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
	this->name = other.name +"_clap_name";
	this->attackDamage = FragTrap::attackDamage;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	return *this;
}
