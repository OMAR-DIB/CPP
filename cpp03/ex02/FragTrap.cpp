#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " created." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " Destroyed." << std::endl;
}

// void FragTrap::attack(const std::string& target) {
// 	if (hitPoints <= 0 || energyPoints <= 0) {
// 		std::cout << "FragTrap " << name << " has no hit points or energy left to attack." << std::endl;
// 		return ;
// 	}
// 	energyPoints--;
//     std::cout << "FragTrap " << name << " attacks " << target << ", causing "
// 		<< attackDamage << " points of damage!" << std::endl;
// }

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << name << " is now in request high 5 guys." << std::endl;
}

FragTrap::FragTrap(FragTrap& other) : ClapTrap(name) {
	*this = other;
}

FragTrap& FragTrap::operator = (const FragTrap& other) {
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}	
	return *this;
}