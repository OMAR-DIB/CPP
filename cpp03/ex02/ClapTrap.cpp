#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string Name): HitPoints(10), energy_points(10), AttackDamage(0) {
	this->Name = Name;
	std::cout << "ClapTrap " << this->Name << " Created"<< std::endl;
}

ClapTrap::ClapTrap(ClapTrap& other) {
	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->Name << " Destroyed"<< std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& other) {
	if (this != &other)
	{
		AttackDamage = other.AttackDamage;
		energy_points = other.energy_points;
		HitPoints = other.HitPoints;
		Name = other.Name;
	}
			
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (energy_points <= 0 || HitPoints <= 0){
		std::cout << "ClapTrap " << Name << " has no hit points or energy left to attack." << std::endl;
		return ;
	}
	energy_points--;
	std::cout << "ClapTrap " << Name << " attacks " << target << ", causing "
		<< AttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (HitPoints <= 0){
		HitPoints = 0;
	}
	HitPoints -= amount;
	std::cout << "ClapTrap " << Name << " takes " << amount <<
		" points of damage. Current HP: " << HitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (HitPoints <= 0 || energy_points <= 0) {
            std::cout << "ClapTrap " << Name <<
				" has no hit points or energy left to repair." << std::endl;
            return;
    }
	HitPoints += amount;
	energy_points--;
	std::cout << "ClapTrap " << Name << " repairs itself, recovering "
		<< amount << " hit points. Current HP: " << HitPoints << std::endl;
}