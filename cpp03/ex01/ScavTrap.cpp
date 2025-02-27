#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " created." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " Destroyed." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other){
    if (this != &other)
	{
        ClapTrap::operator=(other);
	}
    std::cout << "ScavTrap " << name << " has been assigned!\n";
    
	return *this;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& other) {
    *this = other;
}

void ScavTrap::attack(const std::string& target)
{
    if (energyPoints <= 0 || hitPoints <= 0){
        std::cout << "ScavTrap " << name << " has no hit points or energy left to attack." << std::endl;
        return ;
    }
    energyPoints--;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
        << attackDamage << " points of damage!" << std::endl;
}