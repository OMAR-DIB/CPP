#pragma once

#include <iostream>
#include <string>
class ClapTrap
{
protected:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;

public:
	ClapTrap(std::string name);
	ClapTrap();
	~ClapTrap();

	ClapTrap(ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName() const;

	void setName(const std::string &newName);

	int getHitPoints() const;

	void setHitPoints(int newHitPoints);

	int getEnergyPoints() const;

	void setEnergyPoints(int newEnergyPoints);

	int getAttackDamage() const;

	void setAttackDamage(int newAttackDamage);
};