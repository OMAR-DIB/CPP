#pragma once

#include <iostream>
#include <string>
class  ClapTrap
{
private:
	std::string name;
 	int hitPoints;
 	int energyPoints ;
	int attackDamage ;
public:
	ClapTrap(std::string name );
	ClapTrap();
	~ClapTrap();
	
	ClapTrap(ClapTrap& other);
	ClapTrap& operator = (const ClapTrap& other); 
	void attack(const std::string& target);
	void takeDamage(unsigned int amount); 
	void beRepaired(unsigned int amount);
};