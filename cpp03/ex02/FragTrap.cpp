#include "FragTrap.hpp"

FragTrap::FragTrap(std::string Name) : ClapTrap(Name) {
	this->HitPoints = 100;
	this->energy_points = 100;
	this->AttackDamage = 30;
	std::cout << "FragTrap " << this->Name << " created." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->Name << " Destroyed." << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (HitPoints <= 0 || energy_points <= 0) {
		std::cout << "FragTrap " << Name << " has no hit points or energy left to attack." << std::endl;
		return ;
	}
	energy_points--;
    std::cout << "FragTrap " << Name << " attacks " << target << ", causing "
		<< AttackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << Name << " is now in request high 5 guys." << std::endl;
}

FragTrap::FragTrap(FragTrap& other) : ClapTrap(Name) {
	*this = other;
}

FragTrap& FragTrap::operator = (const FragTrap& other) {
	if (this != &other)
	{
		this->AttackDamage = other.AttackDamage;
		this->energy_points = other.energy_points;
		this->HitPoints = other.HitPoints;
		this->Name = other.Name;
	}	
	return *this;
}