#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : hitPoints(10), energyPoints(10), attackDamage(0)
{
	this->name = name;
	std::cout << "ClapTrap " << name << " Created" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &other)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " Destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		attackDamage = other.attackDamage;
		energyPoints = other.energyPoints;
		hitPoints = other.hitPoints;
		name = other.name;
	}

	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " has no energy left to attack." << std::endl;
		return;
	}
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " has no hit points left to attack." << std::endl;
		return;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
			  << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		// hitPoints = 0;
		std::cout << "ClapTrap " << name << " has no hit points left to attack." << std::endl;
		return;
	}
	hitPoints -= amount;
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage. Current HP: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " has no energy left to attack." << std::endl;
		return;
	}
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " has no hit points left to attack." << std::endl;
		return;
	}
	hitPoints += amount;
	energyPoints--;
	std::cout << "ClapTrap " << name << " repairs itself, recovering "
			  << amount << " hit points. Current HP: " << hitPoints << std::endl;
}

std::string ClapTrap::getName() const
{
	return name;
}

void ClapTrap::setName(const std::string &newName)
{
	name = newName;
}

int ClapTrap::getHitPoints() const
{
	return hitPoints;
}

void ClapTrap::setHitPoints(int newHitPoints)
{
	hitPoints = newHitPoints;
}

int ClapTrap::getEnergyPoints() const
{
	return energyPoints;
}

void ClapTrap::setEnergyPoints(int newEnergyPoints)
{
	energyPoints = newEnergyPoints;
}

int ClapTrap::getAttackDamage() const
{
	return attackDamage;
}

void ClapTrap::setAttackDamage(int newAttackDamage)
{
	attackDamage = newAttackDamage;
}