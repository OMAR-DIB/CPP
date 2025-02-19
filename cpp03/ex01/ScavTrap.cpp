#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name) {
	this->HitPoints = 100;
	this->energy_points = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap " << this->Name << " created." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->Name << " Destroyed." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other){
    if (this != &other)
	{
        AttackDamage = other.AttackDamage;
		energy_points = other.energy_points;
		HitPoints = other.HitPoints;
		Name = other.Name;
	}
    
	return *this;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << Name << " is now in Gate Keeper mode." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& other) : ClapTrap(Name) {
    *this = other;
}

void ScavTrap::attack(const std::string& target)
{
    if (energy_points <= 0 || HitPoints <= 0){
        std::cout << "ScavTrap " << Name << " has no hit points or energy left to attack." << std::endl;
        return ;
    }
    energy_points--;
    std::cout << "ScavTrap " << Name << " attacks " << target << ", causing "
        << AttackDamage << " points of damage!" << std::endl;
}