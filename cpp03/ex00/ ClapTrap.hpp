#pragma once

#include <iostream>
#include <string>
class  ClapTrap
{
private:
	std::string Name;
 	int HitPoints = 10;
 	int energy_points = 10;
	int AttackDamage = 0
public:
	 ClapTrap(/* args */);
	~ ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount); 
	void beRepaired(unsigned int amount);
	ClapTrap& operator = (const ClapTrap& other);
};