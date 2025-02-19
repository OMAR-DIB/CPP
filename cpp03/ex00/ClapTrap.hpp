#pragma once

#include <iostream>
#include <string>
class  ClapTrap
{
private:
	std::string Name;
 	int HitPoints;
 	int energy_points ;
	int AttackDamage ;
public:
	ClapTrap(std::string Name );
	~ClapTrap();
	
	ClapTrap(ClapTrap& other);
	ClapTrap& operator = (const ClapTrap& other); 
	void attack(const std::string& target);
	void takeDamage(unsigned int amount); 
	void beRepaired(unsigned int amount);
};