#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name):{
		std::cout << "ClapTrap " << this->name << " Created"<< std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " Destroyed"<< std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	energy_points--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
		<< attack_damage << " points of damage!" << std::endl;
}
